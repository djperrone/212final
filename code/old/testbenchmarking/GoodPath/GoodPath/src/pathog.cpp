#include "path.h"

Path::Path(std::string filename, int numRows, int numCols)
	:fname(filename), nRows(numRows),nCols(numCols),
	map(numRows, std::vector<int>(numCols)),
	visitedVec(numRows, std::vector<bool>(numCols,0))
{
	InitMap();	
	Lr = Lc = Hr = Hc = 0;	
	left = right = up = down = 0;
}

void Path::InitMap()
{
	std::ifstream inFile;
	inFile.open(fname);
	std::string line;
	int val;

	for (int i =0; std::getline(inFile, line); i++)
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
	return GetPath(Lr, Lc);
}

// row, col are low points
bool Path::GetPath(int row, int col)
{	//need to make sure i stick with one direction as long as i can

	//start on high point
	//base case if row, col == low point
	
	if (row == Hr && col == Hc)
		return 1;
	if (row >= 0 && row < nRows && col >= 0 && col < nCols)
	{
		if (isValid(row, col - 1, map[row][col]) && !left)
		{
			
			while (isValid(row, col - 1, map[row][col]))
			{
				std::cout << row << ' ' << col << std::endl;
				visitedVec[row][col] = 1;

				visitedVec[row][col - 1] = 1;
				GetPath(row, col - 1);
			}
			left = 1;
			right = 0;
			up = 0;
			down = 0;
			GetPath(row, col + 1);

		
		}
		else
		{
			visitedVec[row][col] = 0;
			if(row >= 0 && row < nRows&& col+1 >= 0 && col+1 < nCols)
				visitedVec[row][col+1] = 0;

		}
		if (isValid(row - 1, col, map[row][col])&&!up)
		{
			
			while (isValid(row - 1, col, map[row][col]))
			{
				std::cout << row << ' ' << col << std::endl;
				visitedVec[row][col] = 1;

				visitedVec[row - 1][col] = 1;
				GetPath(row - 1, col);
			}
			up = 1;
			down = 0;
			left = 0;
			right = 0;
			GetPath(row + 1, col);
			visitedVec[row][col] = 0;
			if (row + 1 >= 0 && row + 1 < nRows && col >= 0 && col < nCols)
				visitedVec[row + 1][col] = 0;			
		}
		else
		{
			

		}		

		if (isValid(row, col + 1, map[row][col])&& !right)
		{
			while (isValid(row, col + 1, map[row][col]))
			{
				std::cout << row << ' ' << col << std::endl;
				visitedVec[row][col] = 1;

				visitedVec[row][col + 1];
				GetPath(row, col + 1);
			}
			right = 1;

			left = 0;
			down = 0;
			up = 0;

			GetPath(row, col - 1);
			visitedVec[row][col] = 0;
			if (row >= 0 && row < nRows && col - 1 >= 0 && col - 1 < nCols)
				visitedVec[row][col - 1] = 0;			
		}
		else
		{
			
		}

		if (isValid(row + 1, col, map[row][col]) && !down)
		{
			while (isValid(row + 1, col, map[row][col]))
			{
				std::cout << row << ' ' << col << std::endl;
				visitedVec[row][col] = 1;

				visitedVec[row + 1][col] = 1;
				GetPath(row + 1, col);
			}
			down = 1;

			up = 0;
			left = 0;
			right = 0;

			GetPath(row - 1, col);
			visitedVec[row][col] = 0;
			if (row - 1 >= 0 && row - 1 < nRows && col >= 0 && col < nCols)
				visitedVec[row - 1][col] = 0;			
		}	
		else
		{
			
		}		
	}	
	
	return 0;
}

bool Path::isValid(int row, int col, int num)
{
	if (row >= 0 && row < nRows && col >= 0 && col < nCols && !isVisited(row,col))
	{
		if (map[row][col] >= num)
			return 1;
	}
	
	return 0;
}
bool Path::isVisited(int row, int col)
{
	if (visitedVec[row][col])
		return 1;
	return 0;
}

//bool Path::CheckRow(int& row, int num)
//{
//	
//}
//
//bool Path::CheckCol(int& col, int num)
//{
//
//}


void Path::GetHiLo()
{
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

//bool Path::CheckPath(std::vector<CurrentPath> currentPath)
//{
//	for (int i = 0; i < currentPath.size() - 1; i++)
//	{
//
//	}
//}

//
//bool Path::WithinBounds(int row, int col)
//{
//	if()
//}


void Path::PrintMap()
{
	for (auto i : map) 
	{
		for (auto j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}

	for (auto i : visitedVec)
	{
		for (auto j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
}



//if (isValid(row, col - 1, map[row][col]))
//{
//	std::cout << row << ' ' << col << std::endl;
//
//	GetPath(row, col - 1);
//}
//if (isValid(row - 1, col, map[row][col]))
//{
//	std::cout << row << ' ' << col << std::endl;
//	GetPath(row - 1, col);
//}
//if (isValid(row + 1, col, map[row][col]))
//{
//	std::cout << row << ' ' << col << std::endl;
//
//	GetPath(row + 1, col);
//}
//if (isValid(row, col + 1, map[row][col]))
//{
//	std::cout << row << ' ' << col << std::endl;
//
//	GetPath(row, col + 1);
//}