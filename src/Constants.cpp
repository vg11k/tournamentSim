#include "Constants.h"
using namespace std;

const string Constants::STRING_NAME_CHARACTERISTIC_CAPACITE_COMBAT= "capacite_combat";
const string Constants::STRING_NAME_CHARACTERISTIC_CAPACITE_TIR= "capacite_tir";
const string Constants::STRING_NAME_CHARACTERISTIC_FORCE= "force";
const string Constants::STRING_NAME_CHARACTERISTIC_ENDURANCE= "endurance";
const string Constants::STRING_NAME_CHARACTERISTIC_INITIATIVE= "initiative";
const string Constants::STRING_NAME_CHARACTERISTIC_ATTAQUES= "attaques";
const string Constants::STRING_NAME_CHARACTERISTIC_POINTS_DE_VIE= "points_de_vie";
const string Constants::STRING_NAME_CHARACTERISTIC_COMMANDEMENT="commandement";
const string Constants::STRING_NAME_CHARACTERISTIC_PRIX= "prix";

const string Constants::STRING_NAME_TYPE_PERSONNAGE = "type_personnage";
const string Constants::STRING_VALUE_HERO= "hero";
const string Constants::STRING_VALUE_SEIGNEUR= "seigneur";

const string Constants::STRING_NAME_FACTION= "faction";
const string Constants::STRING_VALUE_VAMPIRE= "vampire";

const string Constants::STRING_NAME_PROFILS = "profils";
const string Constants::STRING_NAME_TYPE_PROFIL= "type_profil";

const string Constants::STRING_NAME_PERSONNAGES= "personnages";
const string Constants::STRING_NAME_NOM_PERSONNAGE= "nom_personnage";




////
const string Constants::STRING_NAME_ACHATS= "achats";
const string Constants::STRING_NAME_OPTIONS= "options";
const string Constants::STRING_NAME_REGLES= "regles";
const string Constants::STRING_NAME_ACHATS_ADDITIONNELS= "achats_additionnels";
const string Constants::STRING_NAME_PROFILS_ELIGIBLES= "profils_eligibles";
const string Constants::STRING_NAME_NECESSITE= "necessite";
const string Constants::STRING_NAME_AJOUT_REGLES= "ajout_regles";

const string Constants::STRING_NAME_NOM_OPTION= "nom_option";
const string Constants::STRING_NAME_NOM_ACHAT= "nom_achat";
const string Constants::STRING_NAME_NOM_REGLE= "nom_regle";
const string Constants::STRING_NAME_NOM_CARACTERISTIQUE= "nom_caracteristique";

const string Constants::STRING_NAME_VALEUR_REGLE= "valeur_regle";
const string Constants::STRING_NAME_VALEUR_ACHATS= "valeur_achat";

const string Constants::STRING_NAME_REGLE_AMELIORATION_CAPACITE_COMBAT="amelioration_capacite_combat";
const string Constants::STRING_NAME_REGLE_AMELIORATION_ARMURE="amelioration_armure";
const string Constants::STRING_NAME_REGLE_AMELIORATION_ATTAQUES="amelioration_attaques";
const string Constants::STRING_NAME_REGLE_AMELIORATION_POINTS_DE_VIE="amelioration_points_de_vie";
const string Constants::STRING_NAME_REGLE_AMELIORATION_ENDURANCE="amelioration_endurance";
const string Constants::STRING_NAME_REGLE_AMELIORATION_FORCE="amelioration_force";
const string Constants::STRING_NAME_REGLE_AMELIORATION_INITIATIVE="amelioration_initiative";
const string Constants::STRING_NAME_REGLE_AMELIORATION_REGENERATION="amelioration_regeneration";
const string Constants::STRING_NAME_REGLE_AMELIORATION_SAUVEGARDE_INVULNERABLE="amelioration_sauvegarde_invulnerable";

const std::string Constants::STRING_NAME_REGLE_CHANGEMENT_INITIATIVE= "changement_initiative";
const std::string Constants::STRING_NAME_REGLE_CHANGEMENT_FORCE="changement_force";
const std::string Constants::STRING_NAME_REGLE_CHANGEMENT_ATTAQUES="changement_attaques";

const string Constants::STRING_VALUE_REGLE_MORTVIVANT= "mort-vivant";
const string Constants::STRING_VALUE_REGLE_ATTAQUES_MAGIQUES= "attaques_magiques";
const string Constants::STRING_VALUE_REGLE_COUP_FATAL= "coup_fatal";
const string Constants::STRING_VALUE_REGLE_BLESSURES_MULTIPLES= "blessures_multiples";
const string Constants::STRING_VALUE_REGLE_VAMPIRIQUE= "vampirique";
const string Constants::STRING_VALUE_REGLE_PEUR= "peur";
const string Constants::STRING_VALUE_REGLE_REGENERATION= "regeneration";
const string Constants::STRING_VALUE_REGLE_PIETINEMENT= "pietinement";
const string Constants::STRING_VALUE_REGLE_BLESSURE_GENERE_ATTAQUE="blessure_genere_attaque";
const string Constants::STRING_VALUE_REGLE_RELANCE_TOUCHE="relance_touche";
const string Constants::STRING_VALUE_REGLE_PEUR_DE_ADDITIONNEL="peur_de_additionnel";
const string Constants::STRING_VALUE_REGLE_PEUR_RESULTAT_BRIDE="peur_resultat_bride";
const string Constants::STRING_VALUE_REGLE_DISTRAYANT="distrayant";
const string Constants::STRING_VALUE_REGLE_REFLEXE_FOUDROYANT="reflexe_foudroyant";
const string Constants::STRING_VALUE_REGLE_SEDUCTION="seduction";
const string Constants::STRING_VALUE_REGLE_DISTRAYANT_CONDITIONNE="distrayant_conditionne";
const string Constants::STRING_VALUE_REGLE_AUTORITE="autorite";
const string Constants::STRING_VALUE_REGLE_BAISSE_COMMANDEMENT_ENNEMI="baisse_commandement_ennemi";
const string Constants::STRING_VALUE_REGLE_ENNEMI_RELANCE_PEUR="ennemi_relance_peur";
const string Constants::STRING_VALUE_REGLE_HAINE="haine";
const string Constants::STRING_VALUE_REGLE_INFANTERIE_MONSTRUEUSE="infanterie_monstrueuse";

const string Constants::STRING_VALUE_REGLE_ATTAQUES_EMPOISONNEES="attaques_empoisonnees";
const string Constants::STRING_VALUE_REGLE_PERFORANT="perforant";
const string Constants::STRING_VALUE_REGLE_IMMUNISE_PSYCHOLOGIE="immunise_psychologie";
const string Constants::STRING_VALUE_REGLE_SAUVEGARDE_INVULNERABLE="sauvegarde_invulnerable";

//equipement commun
const string Constants::STRING_VALUE_ACHAT_OBJET_MAGIQUE= "objets_magique";
const string Constants::STRING_VALUE_ACHAT_BOUCLIER= "bouclier";
const string Constants::STRING_VALUE_ACHAT_ARMURE_LEGERE= "armure_legere";
const string Constants::STRING_VALUE_ACHAT_ARMURE_LOURDE= "armure_lourde";
const string Constants::STRING_VALUE_ACHAT_PAIRE_ARMES= "paire_armes";
const string Constants::STRING_VALUE_ACHAT_HALLEBARDE= "hallebarde";
const string Constants::STRING_VALUE_ACHAT_ARME_LOURDE= "arme_lourde";
const string Constants::STRING_VALUE_ACHAT_LANCE_CAVALERIE= "lance_de_cavalerie";

//slots
const std::string Constants::STRING_VALUE_SLOT_BOUCLIER= "bouclier";
const std::string Constants::STRING_VALUE_SLOT_ARMURE_TORSE= "armure_torse";
const std::string Constants::STRING_VALUE_SLOT_ARME_CORPS_A_CORPS= "arme_corps_a_corps";
const std::string Constants::STRING_VALUE_SLOT_ARME_CAVALERIE="arme_cavalerie";

const std::string Constants::STRING_VALUE_CONDITION_TOUR_DE_CHARGE="tour_de_charge";
