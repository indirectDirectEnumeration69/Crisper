#pragma once
//server command functionality.
#include <iostream>
#include <thread>
#include <chrono>
#include <WS2tcpip.h>
#include <mutex>
#include <shared_mutex>

/*
            if (cmdCommand == "hello") {
                std::cout << "Hello, user from server!\n";
            }
            else if (cmdCommand == "exit") {
                std::cout << "Exiting...\n";
            }
            else {
                std::cout << "Invalid command!\n";
            }
            */

class ServerCommandFunctionality {
public:
    void stop() {
        system("cls");
        std::cout << "\033[32m"<<"Now stopping...."<< "\033[0m"<<"\n";
        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1800));
        system("cls");
    }

    void continueCmd() {
      
    }

    void pause() {
      
    }

    void details() {
        
    }

    void help() {
        
    }

    void back() {
       
    }

    void runningThreads() {
        
    }

    void module() {
       
    }

    void neuralStat() {
        
    }

    void commandList() {
        
    }

    void createServer() {
       
    }

    void serverStatus() {
       
    }

    void changeModule() {
        
    }

    void changeServer() {
       
    }

    void changeNeuralNetwork() {
        
    }

    void serverList() {
        
    }

    void serverDetails() {
       
    }

    void serverCommands() {
        
    }

    void attachModule() {
        
    }

    void options() {
      
    }

    void payloadOptions() {
       
    }

    void payloadList() {
        
    }

    void run() {
       
    }

    void exitCmd() {
        
    }

    void displayServerMessages() {
       
    }

    void hideServerMessages() {
       
    }

    void displayServerErrors() {
       
    }

    void fix() {
       
    }

    void runningPorts() {
      
    }

    void myDetails() {
      
    }

    void myCommands() {
      
    }

    void moduleList() {
     
    }

    void serverUptime() {
        
    }
};

