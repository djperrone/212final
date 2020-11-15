#pragma once
#include <fstream>
#include <string>
#include "rk.h"

<<<<<<< HEAD
#define algorithm __FUNCTION__

class CompTool
{
private:
	std::string m_outFile,m_inFile;

public:
	CompTool()
		:m_outFile("comps.csv"), numLines(0), lineLength(0), totalComps(0), fPositives(0),m_funcName("na") {}
	CompTool(std::string outname,std::string inname)
	:m_outFile(outname.append(".csv")),m_inFile(inname), numLines(0), lineLength(0), totalComps(0), fPositives(0),m_funcName("na") {}

	void WriteFile();
	std::string m_outFile,m_funcName;
=======
class CompTool
{
private:
	std::string m_outFile;
	
	
public:	
	CompTool()
		:m_outFile("output.txt"), numLines(0), lineLength(0), totalComps(0), fPositives(0) {}

	void WriteFile();
	std::string m_fname;
>>>>>>> cb218b3a77751bcaae0797331dae5c072ec3abaa
	int numLines;
	int lineLength;
	int totalComps;
	int fPositives;
	int mod;

	inline int avgLineLength() { return totalComps / numLines; }
<<<<<<< HEAD
=======
	
>>>>>>> cb218b3a77751bcaae0797331dae5c072ec3abaa
};

void CompTool::WriteFile()
{
	std::ofstream oStream;
	oStream.open(m_outFile);
<<<<<<< HEAD
	oStream << "file_name,file_length,total_comps,false_positives,avg_line_length" << std::endl;
	oStream << m_inFile<<","<< numLines << ","<<totalComps<<","<< fPositives<<","<<avgLineLength();
=======
	oStream << "file_name,"<<"file_length,total_comps,false_positives,avg_line_length" << std::endl;
	oStream << m_fname<<","<<numLines << ","<<totalComps<<","<<fPositives<<","<<avgLineLength();
>>>>>>> cb218b3a77751bcaae0797331dae5c072ec3abaa
	oStream.close();
}


<<<<<<< HEAD








// #pragma once
// #include <fstream>
// #include <string>
// #include "rk.h"

// class CompTool
// {
// private:
// 	std::string m_outFile;


// public:
// 	CompTool()
// 		:m_outFile("output.txt"), numLines(0), lineLength(0), totalComps(0), fPositives(0) {}

// 	void WriteFile();
// 	std::string m_fname;
// 	int numLines;
// 	int lineLength;
// 	int totalComps;
// 	int fPositives;
// 	int mod;

// 	inline int avgLineLength() { return totalComps / numLines; }

// };

// void CompTool::WriteFile()
// {
// 	std::ofstream oStream;
// 	oStream.open(m_outFile);
// 	oStream << "file_name,"<<"file_length,total_comps,false_positives,avg_line_length" << std::endl;
// 	oStream << m_fname<<","<<numLines << ","<<totalComps<<","<<fPositives<<","<<avgLineLength();
// 	oStream.close();
// }


=======
>>>>>>> cb218b3a77751bcaae0797331dae5c072ec3abaa
