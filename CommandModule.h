#pragma once
class CommandModule
{
	public:
		CommandModule() {
			std::cout << "you have now started the command module" << std::endl;
		}

		int LoadNetwork() {




			return 1;
		}



private:

	using Crisper = CommandModule(*)(int);
	Crisper CrisperNet = nullptr;
};

