#pragma once
#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;

int Loader() {
    bool validationCertain[] = { false, false, false, false, false };

    std::cout << "Starting CrisperNet..." << std::endl;
    std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(2000));
    std::cout << "validation checks" << std::endl;
    int* Secret = new int[5];
    Secret[0] = 0x43;
    Secret[1] = 0x72; //will make dynamic when i have time
    Secret[2] = 0x69;
    Secret[3] = 0x73;
    Secret[4] = 0x70;

    std::thread* SecretThreads = new std::thread[5];

    for (int i = 0; i < 5; i++) {

        SecretThreads[i] = std::thread([i, Secret]() {
            mtx.lock();
            std::cout << "Thread " << i << ": " << Secret[i] << std::endl;
            mtx.unlock();
            });

        switch (Secret[i]) {
        case 0x43:

            if (i == 0) {
                validationCertain[0] = true;
            }
            else {
                validationCertain[0] = false;
            }
            break;

        case 0x72:
            if (i == 1) {
                validationCertain[1] = true;
            }
            else {
                validationCertain[1] = false;
            }
            break;

        case 0x69:
            if (i == 2) {
                validationCertain[2] = true;
            }
            else {
                validationCertain[2] = false;
            }
            break;

        case 0x73:

            if (i == 3) {
                validationCertain[3] = true;
            }
            else {
                validationCertain[3] = false;
            }
            break;

        case 0x70:

            if (i == 4) {
                validationCertain[4] = true;
            }
            else {
                validationCertain[4] = false;
            }
            break;


        }

        if (validationCertain[i] == true) {
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(2030));
            std::cout << "Validated:" << i << std::endl;

            if (i == 4) {
                std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
                std::cout << "Now loading...\n" << std::endl;
            }
        }
        else {
            std::cout << "secret not valid!";
            break;
        }
    }

    for (int i = 0; i < 5; i++) {
        SecretThreads[i].join();
    }

    delete[] Secret;
    delete[] SecretThreads;

    if (validationCertain[0] && validationCertain[1] && validationCertain[2] && validationCertain[3] && validationCertain[4]) {
        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
        std::cout << "Welcome to CrisperNet!\n";
        return 0;
    }
    else {
        exit(2);
    }
    return 1;
}


class Commands {
public:

    void commandInput(std::string cmdCommand) {
        if (cmdCommand == "hello") {
            std::cout << "Hello, user!\n";
        }
        else if (cmdCommand == "help") {
            std::cout << "Available commands: hello, help, exit,Clean,continue\n";
        }
        else if (cmdCommand == "Clean") {
            system("cls");
        }
        else if (cmdCommand == "continue") {
            CommandModule* cmdModule = new CommandModule();
        }
        else {
            std::cout << "Command not recognized. Try 'help' to get the list of available commands.\n";
        }
    }



    void cmdprompt() {
        Loader();
        std::cout << "\n This is the simple command interface if you wish to load the interface press 'continue' \n" << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
        system("cls");
        std::cout << "Remember If you wish to use the advanced module type 'continue' (this will load the network module) \n" << std::endl;
        std::cout << "\n" << std::endl;
        std::cout << "\033[31m" << "Input Command:" << "\033[0m";
        std::string command;
        do {
            std::cin >> command;
            commandInput(command);
        } while (command != "exit");
    }
};