#pragma once
#include <iostream>
#include "ServerCommandList.h"
#include "CommandFunctionality.h"

//started to refactor commands
class UserInput {
public: 

    bool stopFlag = false;

    void commandInput(std::string cmdCommand) {
        ServerCommands::CommandList* CommandsList = new ServerCommands::CommandList();
        ServerCommandFunctionality* servercomfun = new ServerCommandFunctionality();


        if (cmdCommand == "Stop" || cmdCommand == "Exit") {
            servercomfun->stop();
            stopFlag = true;
        }
        else if (cmdCommand == "Continue") {
            bool ContinueStat = servercomfun->continueCmd();

            if (ContinueStat == false) {
                servercomfun->pause();
            }
        }
        else if (cmdCommand == "Pause") {
            servercomfun->pause();
        }
        else if (cmdCommand == "Details") {
            servercomfun->details();
        }
        else if (cmdCommand == "Help") {
            servercomfun->help();
        }
        else if (cmdCommand == "Back") {
            servercomfun->back();
        }
        else if (cmdCommand == "running threads") {
            servercomfun->runningThreads();
        }
        else if (cmdCommand == "Module") {
            servercomfun->module();
        }
        else if (cmdCommand == "Neural stat") {
            servercomfun->neuralStat();
        }
        else if (cmdCommand == "CommandList") {
            servercomfun->commandList();
        }
        else if (cmdCommand == "Create Server") {
            servercomfun->createServer();
        }
        else if (cmdCommand == "Server status") {
            servercomfun->serverStatus();
        }
        else if (cmdCommand == "change module") {
            servercomfun->changeModule();
        }
        else if (cmdCommand == "change server") {
            servercomfun->changeServer();
        }
        else if (cmdCommand == "change neural network") {
            servercomfun->changeNeuralNetwork();
        }
        else if (cmdCommand == "Server list") {
            servercomfun->serverList();
        }
        else if (cmdCommand == "Server details") {
            servercomfun->serverDetails();
        }
        else if (cmdCommand == "Server commands") {
            servercomfun->serverCommands();
        }
        else if (cmdCommand == "Attach module") {
            servercomfun->attachModule();
        }
        else if (cmdCommand == "Options") {
            servercomfun->options();
        }
        else if (cmdCommand == "Payload Options") {
            servercomfun->payloadOptions();
        }
        else if (cmdCommand == "Payload List") {
            servercomfun->payloadList();
        }
        else if (cmdCommand == "Run") {
            servercomfun->run();
        }
        else if (cmdCommand == "display server messages") {
            servercomfun->displayServerMessages();
        }
        else if (cmdCommand == "hide server messages") {
            servercomfun->hideServerMessages();
        }
        else if (cmdCommand == "display server errors") {
            servercomfun->displayServerErrors();
        }
        else if (cmdCommand == "Fix") {
            servercomfun->fix();
        }
        else if (cmdCommand == "Running ports") {
            servercomfun->runningPorts();
        }
        else if (cmdCommand == "my details") {
            servercomfun->myDetails();
        }
        else if (cmdCommand == "my commands") {
            servercomfun->myCommands();
        }
        else if (cmdCommand == "module list") {
            servercomfun->moduleList();
        }
        else if (cmdCommand == "Server Uptime") {
            servercomfun->serverUptime();
        }
        else {
            std::cout << "Command not recognized, please try again." << std::endl;
        }
        delete CommandsList;
        delete servercomfun;
    }

    void UserInputRequired() {
        std::string UserInput;
        do {
            std::cout << "\033[32m" << "Input Server Command:" << "\033[0m";
            std::cin >> UserInput;
            commandInput(UserInput);
        } while (!stopFlag);
    }
};