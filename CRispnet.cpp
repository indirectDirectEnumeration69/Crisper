#include <iostream>
#include <thread>
#include <mutex>
#include "CommandModule.h"
#include "SimpleCommands.h"




int main() {
    Commands* commander = new Commands();
    commander->cmdprompt();
    return 0;
}