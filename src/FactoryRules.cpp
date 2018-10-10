#include "FactoryRules.hpp"
using namespace std;

map<string, RuleContainer*> FactoryRules::m_catalogue = map<string, RuleContainer*>();

FactoryRules::FactoryRules(){}

FactoryRules::~FactoryRules(){}

void FactoryRules::Register(const string & key, RuleContainer * obj) {
    if(m_catalogue.find(key) == m_catalogue.end()) {
        m_catalogue[key] = obj;
    }
}

RuleContainer * FactoryRules::Create(const string& key) const {
    RuleContainer * tmp = 0;
    /*map<string, RuleContainer*>::const_iterator it = m_catalogue.find(key);
    if(it!=m_catalogue.end())
    {
        tmp=((*it).second)->Clone();
    }
    else {
        string s = string("Nom de regle a cloner inconnu : ") + key;
        perror ( s.c_str());
    }
*/
    return tmp;
}


void FactoryRules::initiate(){}


RuleContainer * FactoryRules::getSubRules(string vanillaRuleName, int value) {


    if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_IMMUNISE_PSYCHOLOGIE)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_IMMUNISE_PSYCHOLOGIE,
                                               value,-1,new vector<string>());
    }

    if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_HAINE)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_HAINE, value, 1, new vector<string>());
    }

    if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_VAMPIRIQUE)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_VAMPIRIQUE, value, -1, new vector<string>());
    }

    if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_PEUR)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_PEUR, value, -1, new vector<string>());
    }

    if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_ATTAQUES_MAGIQUES)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_ATTAQUES_MAGIQUES, value, -1, new vector<string>());
    }

        if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_PERFORANT)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_PERFORANT, value, -1, new vector<string>());
    }

        if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_BLESSURES_MULTIPLES)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_BLESSURES_MULTIPLES, value, -1, new vector<string>());
    }

        if(!vanillaRuleName.compare(Constants::STRING_VALUE_REGLE_REGENERATION)) {
        return new RuleContainer(Constants::STRING_VALUE_REGLE_REGENERATION, value, -1, new vector<string>());
    }

    string error = "regle vanilla inconnue " + string(vanillaRuleName);
    perror( error.c_str() );
}
