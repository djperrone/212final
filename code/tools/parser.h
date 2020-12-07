#pragma once

class Parser {
public:

    Parser();
    Parser(std::string name)
        :fname(name), m_string("") {}

    std::string fname, m_string, key;

    void concatStr();
    void Strip(std::string& line);
    inline void clearStr() { m_string.clear(); }

};    

void Parser::Strip(std::string& line) {

    if (line[0] == ' ' || line[line.length() - 1] == ' ') {
        if (line[0] == ' ') {
            // std::cout<<"before: "<<line<<"*"<<std::endl;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ') {
                    line.erase(0, i);
                    break;
                }
            }
        }

        if (line[line.length() - 1] == ' ') {
            for (int i = line.length() - 1; i >= 0; i--) {
                if (line[i] != ' ') {
                    line.erase(i + 1, line.length());
                    break;
                }
            }
        }
        //std::cout<<"after: "<<line<<"*"<<std::endl;
    }
}

// Concatenate entire file into one string
void Parser::concatStr() {

    std::ifstream inFile;
    inFile.open(fname);
    std::string line;
    int numlines = 0;
    while (std::getline(inFile, line)) {
        //std::cout<<line<<std::endl;
        if (line == "")
            continue;
        Strip(line);
        numlines++;


        line.append("");
        m_string.append(line);
    }
    if(numlines>1)
        m_string.erase(m_string.length()-1);
    inFile.close();
}