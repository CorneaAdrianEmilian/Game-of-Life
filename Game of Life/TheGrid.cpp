#include "TheGrid.h"


void TheGrid::alive_rules(const int (&arr)[9])
{
	for(int i=0;i<9;i++)
	{
		if (arr[i] == 1)
			alive_condition.emplace_back(i);
	}
}
void TheGrid::birth_rules(const int (&arr)[9])
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] == 1)
			birth_condition.emplace_back(i);
	}
}
TheGrid::TheGrid(const int& h,const int& w)
{
	height = h; width = w;
}

void TheGrid::gridMaker()
{
	for(int i=0;i<height;i++)
	{
		std::string temp;
		std::cin >> temp;
		theMap.emplace_back(temp);
	}
}

void TheGrid::alive_evolution()
{
	int neightbourCount = 0;
	std::vector<std::string>::iterator it;
	for(it=theMap.begin();it!=theMap.end();it++)
	{
		for (int i = 0; i < width; i++) 
		{
			if ((*it).at(i) == 'O')
			{
				neightbourCount = searchAround(it, i);
				bool death = true;
				for (int j = 0; j < alive_condition.size(); j++) {
					if (alive_condition.at(j) == neightbourCount) {
						death = false;
						break;
					}
				}
				if(death)
				{
					deathSentence.emplace_back(std::make_unique<M_indexes>(it,i));
				}
			}
		}
	}
}

void TheGrid::birth_evolution()
{
	int neightbourCount = 0;
	std::vector<std::string>::iterator it;
	for (it = theMap.begin(); it != theMap.end(); it++)
	{
		for (int i = 0; i < width; i++)
			if ((*it).at(i) == '.')
			{
				neightbourCount = searchAround(it, i);
				bool revive = false;
				for (int j = 0; j < birth_condition.size(); j++) {
					if (birth_condition.at(j) == neightbourCount) {
						revive = true;
						break;
					}
				}
				if (revive)
				{
					revive_idxs.emplace_back(std::make_unique<M_indexes>(it, i));
				}
			}
	}
	
}

int TheGrid::searchAround(std::vector<std::string>::iterator ite, int& idx)
{
	int neightbours = 0;
	if (idx < width - 1) {
		if ((*ite).at(idx + 1) == 'O')
			neightbours++;
	}
	if (idx > 0) {
		if ((*ite).at(idx - 1) == 'O')
			neightbours++;
	}
	if (ite != theMap.begin()) {
		if (idx > 0) {
			if ((*(ite - 1)).at(idx - 1) == 'O')
				neightbours++;
		}
		if (idx < width - 1) {
			if ((*(ite - 1)).at(idx + 1) == 'O')
				neightbours++;
		}
		if((*(ite - 1)).at(idx) == 'O')
			neightbours++;
	}
	if(ite!=theMap.end()-1)
	{
		if (idx > 0) {
			if ((*(ite + 1)).at(idx - 1) == 'O')
				neightbours++;
		}
		if (idx < width - 1) {
			if ((*(ite + 1)).at(idx + 1) == 'O')
				neightbours++;
		}
		if ((*(ite + 1)).at(idx) == 'O')
			neightbours++;
	}
	return neightbours;
}

void TheGrid::eliminateConvicted()
{
	for (int i = 0; i < deathSentence.size(); i++) {
		std::unique_ptr<M_indexes> IDX = std::move(deathSentence.at(i));
		(*(*IDX).getFirst()).at((*IDX).getSecond()) = '.';
	}
	deathSentence.clear();
}

void TheGrid::executeRebirth()
{
	for (int i = 0; i < revive_idxs.size(); i++) {
		std::unique_ptr<M_indexes> IDX = std::move(revive_idxs.at(i));
		(*(*IDX).getFirst()).at((*IDX).getSecond()) = 'O';
	}
	revive_idxs.clear();
}

void TheGrid::printMap()
{
	for(int i=0;i<height;i++)
	{
		std::cout << theMap.at(i) << std::endl;
	}
}
