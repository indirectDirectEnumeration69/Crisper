#pragma once
#include <unordered_map>
#include <unordered_set>
#include <thread>
#include <threadpoolapiset.h>
class ServerCommands {

	struct CommandList {
		
		bool commandsAdded = false;


		struct CommandThreads {
			std::unordered_map<std::string, std::thread> CommandThreads;
		};


		std::unordered_set<std::string> commands{};
		std::unordered_map<std::string, std::string> MappedCommands;

		//neural network will need to be operational here.
		void AddCommand(std::string command, std::string mappedCommand) {
			commands.insert(command);
			MappedCommands.insert(std::make_pair(command, mappedCommand));
		}

		void RemoveCommand(std::string command) {
			commands.erase(command);
			MappedCommands.erase(command);
		}

		



		CommandList() {
			//pull the commands list and check if each command is added
			//database needed for each command
			//neural stat needs it own module
			//switch needed here.
			if (commandsAdded == false) {
				commands.insert("Stop"); //will be different to process exit.
				commands.insert("Continue");
				commands.insert("Pause");
				commands.insert("Details");
				commands.insert("Help");//show commands + help.
				commands.insert("Back");
				commands.insert("running threads");
				commands.insert("Module");
				commands.insert("Neural stat"); //offline for now as we dont have one
				commands.insert("CommandList"); //pull datastruct of commands
				commands.insert("Create Server");
				commands.insert("Server status");
				commands.insert("change module");
				commands.insert("change server");
				commands.insert("change neural network");
				commands.insert("Server list");
				commands.insert("Server details");
				commands.insert("Server commands");
				commands.insert("Attach module");
				commands.insert("Options");
				commands.insert("Payload Options");
				commands.insert("Payload List"); //will have sub command lists.
				commands.insert("Run");
				commands.insert("Exit");
				commands.insert("display server messages");
				commands.insert("hide server messages");
				commands.insert("display server errors");
				commands.insert("Fix"); //try fix server errors automatically
				commands.insert("Running ports");
				commands.insert("my details");
				commands.insert("my commands");
				commands.insert("module list");
				commands.insert("Server Uptime");
			}




			//commands being used?
		}
		
	}; //end of struct commandlist.






	
};