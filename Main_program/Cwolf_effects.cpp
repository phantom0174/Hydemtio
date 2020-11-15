#include <iostream>
#include <windows.h>

void Before_game_start() {
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] Loading main data";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] Loading main data <Finished!>" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] Visualizing the data";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] Visualizing the data <Finished!>" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] Unit constructing";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] Unit constructing <Finished!>" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] Unit visualizing";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] Unit visualizing <Finished!>" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] BGM loading";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] BGM loading <Finished!>" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] Color setting";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] Color setting <Finished!>" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] Data analysing";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] Data analysing <Finished!>" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i <= 2; i++) {
		std::cout << "\r";
		std::cout << "[System.setup] Data saving";
		Sleep(50);
		for(int j = 1; j <= 4; j++) {
			std::cout << ".";
			Sleep(50);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "[System.setup] Data saving <Finished!>" << std::endl;
	std::cout << std::endl;
	Sleep(500);
	system("cls");
}
