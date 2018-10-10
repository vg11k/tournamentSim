#include "FactoryAjout.hpp"

using namespace std;

map<string, Ajout*> * FactoryAjout::m_catalogue = new map<string, Ajout*>();

FactoryAjout::FactoryAjout(){}

FactoryAjout::~FactoryAjout()
{
    //dtor
}

void FactoryAjout::Register(const string & key, Ajout * obj) {
    if(m_catalogue->find(key) == m_catalogue->end()) {
        m_catalogue->insert(pair<string, Ajout*>(key,obj));
    }
}

Ajout * FactoryAjout::Create(const string& key) const {
    Ajout * tmp = 0;
    map<string, Ajout*>::const_iterator it = m_catalogue->find(key);
    if(it!=m_catalogue->end())
    {
        tmp=((*it).second)->Clone();
    }
    else {
        string s = string("Nom d'ajout a cloner inconnu : ") + key;
        perror ( s.c_str());
    }

    return tmp;
}

void FactoryAjout::initiate(){

    vector<string> * slotsBouclier = new vector<string>();
    slotsBouclier->push_back(Constants::STRING_VALUE_SLOT_BOUCLIER);
    Item * bouclier = new Item(Constants::STRING_VALUE_ACHAT_BOUCLIER, slotsBouclier);
    bouclier->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_AMELIORATION_ARMURE,1,-1,new vector<string>()));
    Register(Constants::STRING_VALUE_ACHAT_BOUCLIER, bouclier);

    vector<string> * slotsArmureLourde = new vector<string>();
    slotsArmureLourde->push_back(Constants::STRING_VALUE_SLOT_ARMURE_TORSE);
    Item * armureLourde = new Item(Constants::STRING_VALUE_ACHAT_ARMURE_LOURDE, slotsArmureLourde);
    armureLourde->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_AMELIORATION_ARMURE,2,-1,new vector<string>()));
    Register(Constants::STRING_VALUE_ACHAT_ARMURE_LOURDE, armureLourde);

    vector<string> * slotsPaireArmes = new vector<string>();
    slotsPaireArmes->push_back(Constants::STRING_VALUE_SLOT_ARME_CORPS_A_CORPS);
    Item * paireArmes = new Item(Constants::STRING_VALUE_ACHAT_PAIRE_ARMES, slotsPaireArmes);
    paireArmes->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_AMELIORATION_ATTAQUES,1,-1,new vector<string>()));
    paireArmes->addIncompatibilite(Constants::STRING_VALUE_SLOT_BOUCLIER);
    Register(Constants::STRING_VALUE_ACHAT_PAIRE_ARMES, paireArmes);

    vector<string> * slotsArmureLegere = new vector<string>();
    slotsArmureLegere->push_back(Constants::STRING_VALUE_SLOT_ARMURE_TORSE);
    Item * armureLegere = new Item(Constants::STRING_VALUE_ACHAT_ARMURE_LEGERE, slotsArmureLegere);
    armureLegere->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_AMELIORATION_ARMURE,1,-1,new vector<string>()));
    Register(Constants::STRING_VALUE_ACHAT_ARMURE_LEGERE, armureLegere);

    vector<string> * slotsHallebarde = new vector<string>();
    slotsHallebarde->push_back(Constants::STRING_VALUE_SLOT_ARME_CORPS_A_CORPS);
    Item * hallerbarde = new Item(Constants::STRING_VALUE_ACHAT_HALLEBARDE, slotsHallebarde);
    hallerbarde->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_AMELIORATION_FORCE,1,-1,new vector<string>()));
    hallerbarde->addIncompatibilite(Constants::STRING_VALUE_SLOT_BOUCLIER);
    Register(Constants::STRING_VALUE_ACHAT_HALLEBARDE, hallerbarde);

    vector<string> * slotsArmeLourde = new vector<string>();
    slotsArmeLourde->push_back(Constants::STRING_VALUE_SLOT_ARME_CORPS_A_CORPS);
    Item * armeLourde = new Item(Constants::STRING_VALUE_ACHAT_ARME_LOURDE, slotsArmeLourde);
    armeLourde->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_AMELIORATION_FORCE,1,-1,new vector<string>()));
    armeLourde->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_CHANGEMENT_INITIATIVE,0,-1,new vector<string>()));
    armeLourde->addIncompatibilite(Constants::STRING_VALUE_SLOT_BOUCLIER);
    Register(Constants::STRING_VALUE_ACHAT_ARME_LOURDE, armeLourde);

    vector<string> * slotsLanceCavalerie = new vector<string>();
    slotsLanceCavalerie->push_back(Constants::STRING_VALUE_SLOT_ARME_CAVALERIE);
    Item * lanceCavalerie = new Item(Constants::STRING_VALUE_ACHAT_LANCE_CAVALERIE, slotsLanceCavalerie);
    vector<string> * conditionsLance = new vector<string>();
    conditionsLance->push_back(Constants::STRING_VALUE_CONDITION_TOUR_DE_CHARGE);
    lanceCavalerie->addRegle(new RuleContainer(Constants::STRING_NAME_REGLE_AMELIORATION_FORCE,3,1,conditionsLance));
    Register(Constants::STRING_VALUE_ACHAT_LANCE_CAVALERIE, lanceCavalerie);

}
