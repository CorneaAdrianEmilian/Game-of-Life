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
	//vector to store the indexes of cells that must be eliminated
	std::vector<std::unique_ptr<M_indexes>> deathSentence;
	//vector to store the indexes of dead cells that must be resurrected
	std::vector<::std::unique_ptr<M_indexes>> revive_idxs;
	//method to search all the indexes around a specific index in the 2D map
	int searchAround(std::vector<std::string>::iterator ite,int& idx);
public:
	TheGrid(const int& h,const int& w);
	//method that generates the rules by which a cell survives based on the indexes where it finds 1
	void alive_rules(const int (&arr)[9]);
	//method that generates the rules by which a dead cell revives based on the indexes where it finds 1
	void birth_rules(const int (&arr)[9]);
	//method to insert the map
	void gridMaker();
	//based on the survive rules it determinate if a curent alive cell dies or not
	void alive_evolution();
	//based on the revive rules it determinate if a curent dead cell revives or not
	void birth_evolution();
	//method that "kills" the cells that do not meet the survive rules
	void eliminateConvicted();
	//method that "revives" the dead cells that meet the revive rules
	void executeRebirth();
	void printMap();
};