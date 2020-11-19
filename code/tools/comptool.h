#pragma once
#include <fstream>
#include <string>

class CompTool{
private:
	std::string m_inFile, m_outFile, m_functionName;

public:

	int numLines;
	int lineLength;
	int totalComps;
	int fPositives;
	int mod;

	CompTool();
	CompTool(std::string outFile);
	CompTool(std::string outFile, const std::string& book, const std::string& pattern);

	void WriteHeader();
	void WriteCSV();
	void Reset();

	inline void SetName(const std::string& name) { m_inFile = name; };
	inline int avgLineLength() { return totalComps / numLines; }
	inline void Reset(){numLines = lineLength = totalComps = fPositives = 0;}

	CompTool()
		:m_outFile("output.txt"), numLines(0), lineLength(0), totalComps(0), fPositives(0){ WriteHeader(); }
	CompTool(std::string outFile)
		: m_outFile(outFile.append(".csv")), m_inFile("na"), numLines(0), lineLength(0), totalComps(0), fPositives(0)
		{
			WriteHeader();

		}

	CompTool(std::string out, const std::string& book, const std::string& pattern)
		: m_outFile(out.append(".csv")), m_inFile(book), numLines(0), lineLength(0), totalComps(0), fPositives(0)
		{
			WriteHeader();
		}

	void WriteCSV(){
		std::ofstream oStream;
		oStream.open(m_outFile, std::ios::app);
		oStream << m_inFile << "," << numLines << "," << totalComps << "," << fPositives << "," << avgLineLength();
		oStream.close();
	}

	void WriteHeader(){
		std::ofstream oStream;
		oStream.open(m_outFile);
		oStream << "file_name," << "file_length,total_comps,false_positives,avg_line_length" << std::endl;
		oStream.close();
	}
};






