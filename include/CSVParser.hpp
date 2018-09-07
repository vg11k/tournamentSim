#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class CSVParser
{
    public:
        CSVParser();
        virtual ~CSVParser();

        typedef std::vector<int> *  intVectorPtr;

        static std::vector<std::vector<int> *> * getCombatGridFromCSV(std::string path);



    protected:

    private:
};

#endif // CSVPARSER_H
