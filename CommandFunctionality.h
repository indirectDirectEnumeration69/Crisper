#pragma once
//server command functionality.
#include <iostream>
#include <thread>
#include <chrono>
#include <WS2tcpip.h>
#include <mutex>
#include <shared_mutex>
#include <string>
class ServerCommandFunctionality {
public:
    void stop() {
        system("cls");
        std::cout << "\033[32m"<<"Now stopping...."<< "\033[0m"<<"\n";
        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1800));
        system("cls");
    }

    bool continueCmd() {
        bool doContinue = false;
        std::string CaptureUserInput = "";
        std::cout << "\033[32m" << "Do you wish to continue?" << "\033[0m" << "\n";
        std::cin >> CaptureUserInput;
        //neural network for machine translation will be used here instead of manual normalizaion.
        if (CaptureUserInput == "yes" || "Yes") {
            return doContinue = true;
        }
        else return doContinue = false;
    }

    void pause() {
        SuspendThread(std::this_thread::get_id); //adding more conditions and logic
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

