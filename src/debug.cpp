#include "debug.hpp"

using namespace std;
using Json = nlohmann::json;

void testJSONParserLib() {


    ifstream infile("jsonExample.json");
    stringstream buffer;
    string resultReaded;

    cout << "Reading from the file" << endl;
    buffer << infile.rdbuf();


    resultReaded = buffer.str();
    cout << resultReaded << endl;

    infile.close();

    // read a JSON file
    ifstream inputFile("jsonExample.json");
    Json jsonObject;
    inputFile >> jsonObject;

    inputFile.close();

    cout << jsonObject["pi"] << endl;
}

void testPersonnageGenerator() {

    ifstream inputFile("rosters/roster1.json");
    Json jsonObject;
    inputFile >> jsonObject;
    inputFile.close();


    int nbPersonnages = jsonObject[Constants::STRING_NAME_PERSONNAGES].size();
    for(int i = 0; i < nbPersonnages; i++) {
        Json jPersonnage  = jsonObject[Constants::STRING_NAME_PERSONNAGES][i];
        Personnage p = jPersonnage;
        p.sePresenter();
    }
}
