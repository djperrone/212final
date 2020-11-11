#include "path.h"

int main() 
{
	int rows = 5, cols = 5;
	std::string filename = "src/Text.txt";
	std::cout << "started\n";
	Path path(filename, rows, cols);

	path.PrintMap();
	path.GetHiLo();
	path.PrintHiLo();
	if (path.call())
	{
		std::cout << "YES";
	}
	else std::cout << "NO";

	std::cout << std::endl;
	path.PrintBoolMap();

}	

