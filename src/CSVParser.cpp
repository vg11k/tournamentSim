#include "CSVParser.hpp"

using namespace std;

CSVParser::CSVParser()
{
    //ctor
}

CSVParser::~CSVParser()
{
    //dtor
}

vector<vector<int> *> * CSVParser::getCombatGridFromCSV(string path)
{
    std::ifstream input( path );
    vector<vector<int> *> * result = new vector<vector<int>*>();

    for( string line; getline( input, line ); )
    {
        vector<int> * currentLine = new vector<int>();
        int found = -1;
        bool lineDone = false;

        while(!lineDone)
        {
            int cursor = found;
            if( line.find(";", cursor + 1) != string::npos)
            {
                found = line.find(";", cursor + 1);
                int val = stoi(line.substr(cursor+1, found));
                currentLine->push_back(val);
                cursor = found;

            }
            else
            {
                lineDone = true;
                int val = stoi( line.substr(cursor+1) );
                currentLine->push_back(val);
            }
        }
        result->push_back(currentLine);
    }

    return result;

}
