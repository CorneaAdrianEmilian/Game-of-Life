#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "mapIDX.h"

class TheGrid 
{
	int height, width;
	std::vector<int> alive_condition;
	std::vector<int> birth_condition;
	std::vector<std::string> theMap;
	std::vector<std::unique_ptr<M_indexes>> deathSentence;
	std::vector<::std::unique_ptr<M_indexes>> revive_idxs;
	int searchAround(std::vector<std::string>::iterator ite,int& idx);
public:
	TheGrid(int& h, int& w);
	void alive_rules(int (&arr)[9]);
	void birth_rules(int (&arr)[9]);
	void gridMaker();
	void alive_evolution();
	void birth_evolution();
	void eliminateConvicted();
	void executeRebirth();
	void printMap();
};