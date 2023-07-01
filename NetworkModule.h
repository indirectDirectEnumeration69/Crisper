#pragma once
#include <WinSock2.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

class Server {
public:
    struct ServerInst {
        bool ServerRunning = false;
        std::thread ServerThread;

        void ServerThreadFunc() {
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(2000));
            std::cout << "\033[32m" << "Server Thread Running..." << "\033[0m" << std::endl;

            WSADATA wsaData;
            int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
            if (iResult != 0) {
                std::cout << "WSAStartup failed: " << iResult << "\n";//adding exeception handlers.
                return;
            }

            SOCKET ListenSocket = INVALID_SOCKET;
            struct addrinfo* result = NULL, * ptr = NULL, hints;
            ZeroMemory(&hints, sizeof(hints));
            hints.ai_family = AF_INET;
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_protocol = IPPROTO_TCP;
            hints.ai_flags = AI_PASSIVE;

            if (getaddrinfo(NULL, "8080", &hints, &result) != 0) {
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
            std::cout <<"\033[32m"<<"Server is listening on port 8080..." << "\033[0m" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(10));

           
            closesocket(ListenSocket);
            WSACleanup();
            std::cout <<  "\033[32m"<< "Server has shut down."<< "\033[0m"<<std::endl;
        }//server thread function end.
        ~ServerInst() {
            if (ServerThread.joinable()) {
                ServerThread.join();
            }
        }
    };

    class NetworkModule {
    public:
        ServerInst ServerInstance;

        NetworkModule() {
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
            system("cls");

            if (ServerInstance.ServerRunning == false) {
                std::cout << "\033[32m" << "Starting Server..." << "\033[0m" << std::endl;
                ServerInstance.ServerThread = std::thread(&ServerInst::ServerThreadFunc, &ServerInstance);
                ServerInstance.ServerRunning = true;
            }
            else {
                std::cout << "\033[31m" << "Server Already Running!" << "\033[0m" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
            std::cout << "\n";
            std::cout << "\033[32m" << "Network Loaded" << "\033[0m" << std::endl;
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
