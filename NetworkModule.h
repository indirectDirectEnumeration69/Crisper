#pragma once
#include <WinSock2.h>

class Server {
public:
	Server(){
		NetworkModule* Network = new NetworkModule();
	}



	class NetworkModule
	{
	public:

		NetworkModule() {
			std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
			system("cls");
				std::cout<<"\033[32m" << "Starting Server..." << "\033[0m" << std::endl;
				std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(3000));
				std::cout << "\n";
				std::cout<<"\033[32m" << "Network Loaded" << "\033[0m" << std::endl;
		}

		~NetworkModule() {


		}


	};
private:
	Server* ServerNet = nullptr;
};