#pragma once
#include <unordered_map>
#include <unordered_set>
#include <thread>
#include <threadpoolapiset.h>
class ServerCommands {

	struct CommandList {

		struct CommandThreads {
			std::unordered_map<std::string, std::thread> CommandThreads;
		};

		std::unordered_set<std::string> commands;
		std::unordered_map<std::string, std::string> MappedCommands;



		CommandList() {
			//commands being used?
		}
	};








	
};