#include "TheGrid.h"
#include <iostream>
#include <Windows.h>

int main()
{
	int height = 0, width = 0, turns = 0;
	std::cout << "Insert height, width of the grid and number of turns\n";
	std::cin >> height >> width >> turns;
	std::string intermediate;
	int alive_rules[9];
	int birth_rules[9];
	std::cout << "Insert 9 not space separated binary integers, the condition of surviving of a living cell (0: dies, 1: stays alive). \n";
	std::cin >> intermediate;
	for (int i = 0; i < 9; i++) {
		std::string temp = intermediate.substr(i, 1);
		alive_rules[i] = std::stoi(temp);
	}
	std::cout << "Insert 9 not space separated binary integers, the condition of birth of a dead cell (0: stays dead, 1: birth).\n";
	std::cin >> intermediate;
	for (int i = 0; i < 9; i++) {
		std::string temp = intermediate.substr(i, 1);
		birth_rules[i] = std::stoi(temp);
	}
	std::unique_ptr<TheGrid> lifeGame = std::make_unique<TheGrid>(height,width);
	lifeGame->alive_rules(alive_rules);
	lifeGame->birth_rules(birth_rules);
	std::cout << "Create the map:\n";
	std::cout << "Insert " << height << " lines of " << width << "-lenght string for cells  (.: dead, O: alive).\n";
	lifeGame->gridMaker();
	for(int i=0;i<turns;i++)
	{
		lifeGame->alive_evolution();
		lifeGame->birth_evolution();
		lifeGame->eliminateConvicted();
		lifeGame->executeRebirth();
		system("CLS");
		std::cout << std::endl << "The evolution of the cells after " << i+1 << " turn(s):\n";
		lifeGame->printMap();
		Sleep(2000);
		
	}
}