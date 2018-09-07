#include "Tournament.hpp"

using namespace std;
using Json = nlohmann::json;


Tournament::Tournament()
{
    //load all profiles
    m_profileManager = ProfileManager::getMe();



    ifstream inputFile("rosters/roster1.json");
    Json jsonObject;
    inputFile >> jsonObject;
    inputFile.close();


    int nbPersonnages = jsonObject[Constants::STRING_NAME_PERSONNAGES].size();
    m_personnages = new vector<Personnage>();
    for(int i = 0; i < nbPersonnages; i++)
    {
        Json jPersonnage  = jsonObject[Constants::STRING_NAME_PERSONNAGES][i];
        Personnage p = jPersonnage;
        if(p.areYouValid())
        {
            m_personnages->push_back(p);
        }
    }

    m_CCvsCCgrid = CSVParser::getCombatGridFromCSV("CCvsCC.csv");
    m_FvsEgrid = CSVParser::getCombatGridFromCSV("FvsE.csv");

}

/*Duelliste * duelliste = p.getDuelliste();
       duelliste->getPersonnage()->sePresenter();
       delete duelliste;*/

Tournament::~Tournament()
{
    //dtor
}


bool Tournament::aTouche(int roll, int CCa, int CCc)
{
    return m_CCvsCCgrid->at(CCc + 1)->at(CCa + 1) <= roll;
}

bool Tournament::aBlesse(int roll, int force, int endu)
{
    vector<int> * line = m_FvsEgrid->at(endu + 1);
    int val = line->at(force + 1);
    return val <= roll;
}

void Tournament::makeFight(Duelliste * d1, Duelliste * d2)
{

    bool sameInit = d1->getInitiative() == d2->getInitiative();
    bool d1AttaqueEnPremier;
    if(d1->getInitiative() > d2->getInitiative())
    {
        d1AttaqueEnPremier = true;
    }
    else
    {
        d1AttaqueEnPremier = false;
    }

    bool stop = false;

    while(!stop)
    {
        Duelliste * premierAAttaquer;
        Duelliste * secondAAttaquer;

        if(d1AttaqueEnPremier)
        {
            premierAAttaquer = d1;
            secondAAttaquer = d2;
        }
        else
        {
            premierAAttaquer = d2;
            secondAAttaquer = d1;
        }

        int CCdueliste1 = premierAAttaquer->getCapaciteCombat();
        int CCdueliste2 = secondAAttaquer->getCapaciteCombat();

        int forceDueliste1 = premierAAttaquer->getForce();
        int forceDueliste2 = secondAAttaquer->getForce();
        int enduranceDueliste1 = premierAAttaquer->getEndurance();
        int enduranceDueliste2 = secondAAttaquer->getEndurance();

        int attaquesDuelliste1 = premierAAttaquer->getAttaques();
        int attaquesDuelliste2 = secondAAttaquer->getAttaques();

        //attaques plus rapide
        for(int attaqueIndex = 0; attaqueIndex < attaquesDuelliste1; attaqueIndex++)
        {
            int roll = rand()%(6);
            cout << roll << " pour toucher " << endl;
            if(aTouche(roll,CCdueliste1, CCdueliste2))
            {
                roll = rand() %(6);
                cout << roll << " pour blesser " << endl;
                if(aBlesse(roll, forceDueliste1, enduranceDueliste2))
                {
                    secondAAttaquer->removeHP(1);
                    cout << secondAAttaquer->getName() << " a perdu un pv." << endl;
                }

            }
        }

        if(sameInit || secondAAttaquer->getCurrentHP() > 0 )
        {
            for(int attaqueIndex = 0; attaqueIndex < attaquesDuelliste2; attaqueIndex++)
            {
                int roll = rand()%(6);
                cout << roll << " pour toucher " << endl;

                if(aTouche(roll,CCdueliste2, CCdueliste1))
            {
                roll = rand() %(6);
                cout << roll << " pour blesser " << endl;
                    if(aBlesse(roll, forceDueliste2, enduranceDueliste1))
                    {
                        premierAAttaquer->removeHP(1);
                        cout << premierAAttaquer->getName() << " a perdu un pv." << endl;
                    }

                }
            }
        }

        //mort simultanee : tout le monde repart avec 1hp pour un nouveau round
        if(premierAAttaquer->getCurrentHP() < 1 && secondAAttaquer->getCurrentHP() < 1) {
            premierAAttaquer->setCurrentHP(1);
            secondAAttaquer->setCurrentHP(1);
        }

        if(premierAAttaquer->getCurrentHP() < 1 || secondAAttaquer->getCurrentHP() <1 )
        {
            stop = true;
            cout << "resultats : " << endl;
            cout << premierAAttaquer->getName() << " a " << premierAAttaquer->getCurrentHP() << " HP" << endl;
            cout << secondAAttaquer->getName() << " a " << secondAAttaquer->getCurrentHP() << " HP" << endl;
        }
    }
}

