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

    // read a JSON
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
    vector<Personnage> * personnages = new vector<Personnage>();
    for(int i = 0; i < nbPersonnages; i++) {
        Json jPersonnage  = jsonObject[Constants::STRING_NAME_PERSONNAGES][i];
        Personnage p = jPersonnage;
        personnages->push_back(p);
        /*Duelliste * duelliste = p.getDuelliste();
        duelliste->getPersonnage()->sePresenter();
        delete duelliste;*/
    }






}


void testCSVParser() {
    vector<vector<int>*>* result = CSVParser::getCombatGridFromCSV("CCvsCC.csv");

    for(unsigned int j = 0; j < result->size(); j++) {
        vector<int> * currentLine = result->at(j);
        for(unsigned int i = 0; i < currentLine->size(); i++)
        {
            cout << currentLine->at(i) << " ";
        }
        cout << endl;
    }
}


void testFight() {

    Tournament tournament;
    vector<Personnage*> * persos = tournament.getPersonnages();

    Duelliste * d1 = persos->at(0)->getDuelliste();
    Duelliste * d2 = persos->at(2)->getDuelliste();
    persos->at(0)->sePresenter();
    d1->sePresenter();
    persos->at(2)->sePresenter();
    d2->sePresenter();
    cout << "duellistes generes" << endl;

    tournament.makeFight(d1, d2);
}
