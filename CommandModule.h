#pragma once
#include "NetworkModule.h"
#include <iostream>
#include <mutex>
class CommandModule
{
public:

		CommandModule() {
			std::cout << "you have now started the command module" << std::endl;
			LoadNetwork();
		}

		int LoadNetwork() {
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			system("cls");
			std::cout << "\033[32m" << "Loading Network..." << "\033[0m" << std::endl;
			Server* server = new Server();
			delete server;
			return 1;
		}



		~CommandModule() {
			std::cout << "you have now closed the command module" << std::endl;
		}

private:

	using Crisper = CommandModule(*)(int);
	Crisper CrisperNet = nullptr;
};

