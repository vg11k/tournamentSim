#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>


class Constants
{
    public:

        static const std::string STRING_NAME_CHARACTERISTIC_CAPACITE_COMBAT;
        static const std::string STRING_NAME_CHARACTERISTIC_CAPACITE_TIR;
        static const std::string STRING_NAME_CHARACTERISTIC_FORCE;
        static const std::string STRING_NAME_CHARACTERISTIC_ENDURANCE;
        static const std::string STRING_NAME_CHARACTERISTIC_INITIATIVE;
        static const std::string STRING_NAME_CHARACTERISTIC_ATTAQUES;
        static const std::string STRING_NAME_CHARACTERISTIC_POINTS_DE_VIE;
        static const std::string STRING_NAME_CHARACTERISTIC_COMMANDEMENT;
        static const std::string STRING_NAME_CHARACTERISTIC_PRIX;


        static const std::string STRING_NAME_TYPE_PERSONNAGE;
        static const std::string STRING_VALUE_SEIGNEUR;
        static const std::string STRING_VALUE_HERO;



        static const std::string STRING_NAME_FACTION;
        static const std::string STRING_VALUE_VAMPIRE;

        static const std::string STRING_NAME_PROFILS;
        static const std::string STRING_NAME_TYPE_PROFIL;
        static const std::string STRING_VALUE_ROI_REVENANT;
        static const std::string STRING_VALUE_VAMPIRE_COURTISAN;
        static const std::string STRING_VALUE_VAMPIRE_SEIGNEUR;


        static const std::string STRING_NAME_PERSONNAGES;
        static const std::string STRING_NAME_NOM_PERSONNAGE;


        virtual ~Constants() {}

    protected:

    private:
         Constants() {}
};

#endif // CONSTANTS_H
