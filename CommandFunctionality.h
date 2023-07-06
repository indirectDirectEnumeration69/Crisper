#pragma once
//server command functionality.
#include <iostream>
#include <thread>
#include <chrono>
#include <WS2tcpip.h>
#include <mutex>
#include <shared_mutex>
#include <string>
#include "Details.h"
#include <atomic>
class ServerCommandFunctionality {
private:
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> pause_thread = false;
public:

    void stop() {
        system("cls");
        std::cout << "\033[32m"<<"Now stopping...."<< "\033[0m"<<"\n";
        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1800));
        system("cls");
    }
    //input normalization will be done with neural network at a later date.
    bool continueCmd() {
        std::string CaptureUserInput = "";
        std::cout << "\033[32m" << "Do you wish to continue?" << "\033[0m" << "\n";
        std::cin >> CaptureUserInput;
        if (CaptureUserInput == "yes" || CaptureUserInput == "Yes") {
            return true;
        }
        else return false;
    }

    void pause() {
        std::unique_lock<std::mutex> lock(mtx);
        pause_thread = true;
        std::cout << "Thread " << std::this_thread::get_id() << " is pausing" << std::endl;
        cv.wait(lock, [&]() { return !pause_thread; });
        std::cout << "Thread " << std::this_thread::get_id() << " has resumed" << std::endl;
    }

    void resume() {
        std::lock_guard<std::mutex> lock(mtx);
        pause_thread = false;
        cv.notify_all();
    }
    //experimenting about with this
    void details() {
        Details<std::thread> ThreadDetails;
        Details<int>ThreadCount;
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

