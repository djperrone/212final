#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Path
{
private:
	std::string fname;
	std::vector< std::vector<int>> map;
	std::vector< std::vector<bool>> visitedVec;
	int nRows, nCols, Lr, Lc, Hr, Hc;
	std::vector<bool> results;



public:
	Path(std::string filename, int nRows, int nCols);

	void InitMap();
	void PrintMap() const;
	void PrintBoolMap() const;

	bool GetPath(int row, int col);
	
	void GetHiLo();

	
	void isValid(int row, int col, int num);
	bool isVisited(int row, int col);

	bool call();
	
	inline void PrintHiLo() const { std::cout << GetLr() << ' ' << GetLc() << ' ' << GetHr() << ' ' << GetHc() << ' '; }
	inline const int GetHr()const { return this->Hr; }
	inline const int GetHc()const { return this->Hc; }
	inline const int GetLr()const { return this->Lr; }
	inline const int GetLc()const { return this->Lc; }

};

