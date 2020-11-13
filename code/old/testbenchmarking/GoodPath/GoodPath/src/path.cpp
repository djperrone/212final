#include "Instrumentator.h"
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
	//std::vector<bool> results;
	int nRows, nCols, Lr, Lc, Hr, Hc;
	bool goodPath;

public:
	Path(std::string filename, int nRows, int nCols);

	void InitMap();
	void PrintMap() const;
	void PrintBoolMap() const;

	void GetPath(int row, int col);

	void GetHiLo();

	void isValid(int row, int col, int num);
	bool isVisited(int row, int col);

	bool call();

	inline void PrintHiLo() const { std::cout << GetLr() + 1 << ' ' << GetLc() + 1 << ' ' << GetHr() + 1 << ' ' << GetHc() + 1 << ' '; }
	inline const int GetHr()const { return this->Hr; }
	inline const int GetHc()const { return this->Hc; }
	inline const int GetLr()const { return this->Lr; }
	inline const int GetLc()const { return this->Lc; }

};

Path::Path(std::string filename, int numRows, int numCols)
	:fname(filename), nRows(numRows), nCols(numCols), //init variables
	map(numRows, std::vector<int>(numCols)), //init map
	visitedVec(numRows, std::vector<bool>(numCols, 0))
{
	PROFILE_FUNCTION();
	InitMap();
	Lr = Lc = Hr = Hc = 0;
	this->goodPath = 0;
}

void Path::InitMap()
{
	PROFILE_FUNCTION();
	std::ifstream inFile;
	inFile.open(fname);
	std::string line;
	int val;

	for (int i = 0; std::getline(inFile, line); i++)
	{
		std::istringstream ss(line);
		for (int j = 0; ss >> val; j++)
		{
			this->map[i][j] = val;
		}
	}
	inFile.close();
}

bool Path::call()
{
	PROFILE_FUNCTION();
	GetPath(Lr, Lc);
	return goodPath;
}

// row, col are low points
void Path::GetPath(int row, int col)
{
	PROFILE_FUNCTION();
	// base case
	if (row == Hr && col == Hc)
	{
		this->goodPath = 1;
		return;
	}

	// Loop for each direction
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			isValid(row + 1, col, map[row][col]);
			break;
		case 1:
			isValid(row - 1, col, map[row][col]);
			break;
		case 2:
			isValid(row, col - 1, map[row][col]);
			break;
		case 3:
			isValid(row, col + 1, map[row][col]);
			break;
		}
	}
}

// Checks if valid and then calls GetPath again
void Path::isValid(int row, int col, int num)
{
	PROFILE_FUNCTION();
	if (row >= 0 && row < nRows && col >= 0 && col < nCols && !isVisited(row, col))
	{
		if (map[row][col] >= num)
		{
			// Mark cell as visited
			visitedVec[row][col] = 1;
			GetPath(row, col);
		}
	}
}
bool Path::isVisited(int row, int col)
{
	PROFILE_FUNCTION();
	if (visitedVec[row][col])
		return 1;
	return 0;
}

void Path::GetHiLo()
{
	PROFILE_FUNCTION();
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			if (map[i][j] < map[Lr][Lc])
			{
				Lr = i;
				Lc = j;
			}
			if (map[i][j] > map[Hr][Hc])
			{
				Hr = i;
				Hc = j;
			}
		}
	}
}

void Path::PrintMap() const
{
	PROFILE_FUNCTION();
	for (auto i : map)
	{
		for (auto j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
}

void Path::PrintBoolMap() const
{
	PROFILE_FUNCTION();
	for (auto i : visitedVec)
	{
		for (auto j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
}


void RunBenchmarks()
{
	PROFILE_SCOPE("RunBenchmarks");
	std::cout << "Running Benchmarks...\n";


	int rows = 5, cols = 5;
	std::string filename = "src/Text.txt";
	std::cout << "started\n";
	Path path(filename, rows, cols);	

	//path.PrintMap();

	path.GetHiLo();
	path.PrintHiLo();
	if (path.call())
	{
		std::cout << "yes";
	}
	else std::cout << "no";

}

int main(int argc, char** argv)
{
	Instrumentor::Get().BeginSession("Profile");
	RunBenchmarks();
	Instrumentor::Get().EndSession();
	//	path.PrintBoolMap();
}