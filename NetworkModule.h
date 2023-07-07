#pragma once
#include <WinSock2.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <WS2tcpip.h>
#include "ServerUserInput.h"
#pragma comment(lib, "ws2_32.lib")

class Server {
public:
    struct ServerInst {
        bool ServerRunning = false;
        std::thread ServerThread;
     
        void ServerSetupFunc(const char* portNum) {
            WSADATA wsaData;
            int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
            if (iResult != 0) {
                std::cout << "WSAStartup failed: " << iResult << "\n";
                return;
            }

            SOCKET ListenSocket = INVALID_SOCKET;
            struct addrinfo* result = NULL, * ptr = NULL, hints;
            ZeroMemory(&hints, sizeof(hints));
            hints.ai_family = AF_INET;
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_protocol = IPPROTO_TCP;
            hints.ai_flags = AI_PASSIVE;

            if (getaddrinfo(NULL, portNum, &hints, &result) != 0) {
                std::cout << "getaddrinfo failed\n";
                WSACleanup();
                return;
            }

            ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
            if (ListenSocket == INVALID_SOCKET) {
                std::cout << "Error at socket(): " << WSAGetLastError() << "\n";
                freeaddrinfo(result);
                WSACleanup();
                return;
            }
            if (bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
                std::cout << "bind failed with error: " << WSAGetLastError() << "\n";
                freeaddrinfo(result);
                closesocket(ListenSocket);
                WSACleanup();
                return;
            }

            freeaddrinfo(result);

            if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
                std::cout << "Listen failed with error: " << WSAGetLastError() << "\n";
                closesocket(ListenSocket);
                WSACleanup();
                return;
            }
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(2000));
            std::cout << "\033[32mServer is listening on port " << portNum << "...\033[0m\n";
            std::this_thread::sleep_for(std::chrono::seconds(4));
            //going to add server uptime ticker .^^^
            //will add a menu list and so on and all the fancy stuff later.

            std::cout << "\n" << "\033[31m" << "Please Select what you wish for the server to now do!" << "\033[0m\n";
            
            CallUser();
       
            //here ill pull in additional modules to handle the server
            //and ill also add a command prompt to the server for specific actions on this port.
            closesocket(ListenSocket);
            WSACleanup();
            std::cout << "\033[32mServer has shut down.\033[0m\n";
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1250));
            system("cls");
        }

        void UserInputFunc() {
            std::string portNum;
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
            std::cout << "\n\033[32mNetwork has been Loaded\033[0m\n";
            std::cout << "Enter a port number to use: ";
            std::cin >> portNum;
            ServerSetupFunc(portNum.c_str());
        }

        ~ServerInst() {
            if (ServerThread.joinable()) {
                ServerThread.join();
            }
        }

        //user enters a command server command header retrieves commands.
        //each command for optimisation will be handled by seperate classes.
        //base class default with sub classes for each command.
        //need to restructure this
    private: 
        UserInput UserInputs;
        
        void CallUser() {
            UserInputs.UserInputRequired();
        }
    };

    class NetworkModule {
    public:
        ServerInst ServerInstance;

        NetworkModule() {
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
            system("cls");

            if (ServerInstance.ServerRunning == false) {
                std::cout << "\033[32mStarting Server...\033[0m\n";
                ServerInstance.ServerThread = std::thread(&ServerInst::UserInputFunc, &ServerInstance);
                ServerInstance.ServerRunning = true;
                ServerInstance.ServerThread.join();
                std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
            }
            else {
                std::cout << "\033[31mServer Already Running!\033[0m\n";
            }
        }

        ~NetworkModule() {
            if (ServerInstance.ServerThread.joinable()) {
                ServerInstance.ServerThread.join();
            }
        }
    };


    Server() {
        NetworkModule* Network = new NetworkModule();
    }
private:
    Server* ServerNet = nullptr;
};
