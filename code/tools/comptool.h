#pragma once
#include <fstream>
#include <string>

class CompTool {
private:
	std::string m_inFile, m_outFile, m_functionName,pattern,m_code;

public:

	int numLines;
	int lineLength;
	int totalComps, innerComps, outterComps;
	int fPositives;
	int m_mod;	
	int patterns_found;

	inline void SetBookName(const std::string& name) { m_inFile = name; };
	inline int avgLineLength() { return lineLength / numLines; }
	void Reset() { numLines = lineLength = totalComps = innerComps = outterComps = patterns_found = fPositives = 0; }

	CompTool()
		:m_outFile("output.csv"), numLines(0), lineLength(0), totalComps(0),patterns_found(0), fPositives(0) {
		WriteHeader();
	}
	// standard constructor - pass in intended outfile title, incoming code, mod
	CompTool(std::string outFile,std::string code, int mod)
		: m_outFile(outFile.append(".csv")), m_inFile("na"),m_code(code), numLines(0), lineLength(0),
		 totalComps(0),innerComps(0),outterComps(0),patterns_found(0), fPositives(0),m_mod(mod)
	{
		WriteHeader();
		

	}

	//bruteforce constructor
	CompTool(std::string outFile, std::string code)
		: m_outFile(outFile.append(".csv")), m_inFile("na"), m_code(code), numLines(0), lineLength(0),
		 totalComps(0),innerComps(0),outterComps(0),patterns_found(0), fPositives(0),m_mod(-1)
	{
		WriteHeader();
	}

	void WriteHeader() {
		std::ofstream oStream;
		oStream.open(m_outFile);
		oStream << "file_name,inner_comps,outter_comps,total_comps,patterns_found,false_positives,avg_line_length," << m_code << "," << m_mod << std::endl;
		oStream.close();
	}

	void WriteCSV() {
		std::ofstream oStream;
		oStream.open(m_outFile, std::ios::app);
		oStream << m_inFile <<  ","<<innerComps<<","<<outterComps<<"," << totalComps << ","<<patterns_found<<"," << fPositives << std::endl;
		oStream.close();
	}

	
};






