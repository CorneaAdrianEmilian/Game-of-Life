#pragma once
#include <vector>
#include <string>
class M_indexes
{
	std::vector<std::string>::iterator first;
	int second;
public:
	M_indexes(const std::vector<std::string>::iterator f,const int& s);
	const inline std::vector<std::string>::iterator getFirst() { return first; };
	const inline int getSecond() { return second; };
};