#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <iostream>
#include <vector>
#include "Duelliste.hpp"
#include "CSVParser.hpp"


class Tournament
{
    public:
        Tournament();
        virtual ~Tournament();

        void makeFight(Duelliste * d1, Duelliste * d2);
        std::vector<Personnage*> * getPersonnages();

    protected:

    private:

        std::vector<Personnage*> *  m_personnages;
        ProfileManager * m_profileManager;

        std::vector<std::vector<int>*>* m_CCvsCCgrid;
        std::vector<std::vector<int>*>* m_FvsEgrid;

        bool aTouche(int roll, int CCa, int CCc);
        bool aBlesse(int roll, int force, int endu);

        void verifierMortSimultanee(Duelliste * d1, Duelliste * d2);
        void effectuerAttaquesDeTir(Duelliste * d1, Duelliste * d2);
        bool peutAttaquer(Duelliste * attaquant, Duelliste * cible);
        void effectuerAttaques(Duelliste * attaquant, Duelliste * cible, int roundCounter, bool tourDeCharge);
        bool blessureAnnulee(Duelliste * attaquant, Duelliste * cible, bool attaqueSpeciale);

        void finDeRound(Duelliste * d1, Duelliste * d2);

        int getNew6D();
        int getNewD(int i);


};

inline std::vector<Personnage*> *  Tournament::getPersonnages(){
    return m_personnages;
}

#endif // TOURNAMENT_H
