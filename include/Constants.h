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

    static const std::string STRING_NAME_PERSONNAGES;
    static const std::string STRING_NAME_NOM_PERSONNAGE;

    static const std::string STRING_NAME_ACHATS;
    static const std::string STRING_NAME_OPTIONS;
    static const std::string STRING_NAME_REGLES;
    static const std::string STRING_NAME_AMELIORATIONS;
    static const std::string STRING_NAME_ACHATS_ADDITIONNELS;
    static const std::string STRING_NAME_PROFILS_ELIGIBLES;
    static const std::string STRING_NAME_NECESSITE;
    static const std::string STRING_NAME_AJOUT_REGLES;

    static const std::string STRING_NAME_NOM_OPTION;
    static const std::string STRING_NAME_NOM_ACHAT;
    static const std::string STRING_NAME_NOM_REGLE;
    static const std::string STRING_NAME_NOM_CARACTERISTIQUE;

    static const std::string STRING_NAME_VALEUR_REGLE;
    static const std::string STRING_NAME_VALEUR_ACHATS;



    static const std::string STRING_VALUE_REGLE_MORTVIVANT;
    static const std::string STRING_VALUE_REGLE_ATTAQUES_MAGIQUES;
    static const std::string STRING_VALUE_REGLE_COUP_FATAL;
    static const std::string STRING_VALUE_REGLE_BLESSURES_MULTIPLES;
    static const std::string STRING_VALUE_REGLE_VAMPIRIQUE;
    static const std::string STRING_VALUE_REGLE_PEUR;

//equipement commun
    static const std::string STRING_VALUE_ACHAT_OBJET_MAGIQUE;
    static const std::string STRING_VALUE_ACHAT_BOUCLIER;
    static const std::string STRING_VALUE_ARMURE_LEGERE;
    static const std::string STRING_VALUE_ARMURE_LOURDE;
    static const std::string STRING_VALUE_ACHAT_PAIRE_ARMES;
    static const std::string STRING_VALUE_ACHAT_HALLEBARDE;
    static const std::string STRING_VALUE_ACHAT_ARME_LOURDE;
    static const std::string STRING_VALUE_ACHAT_LANCE_CAVALERIE;


    virtual ~Constants() {}

protected:

private:
    Constants() {}
};

#endif // CONSTANTS_H
