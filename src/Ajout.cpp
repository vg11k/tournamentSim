#include "Ajout.hpp"

using namespace std;

Ajout::Ajout(string name)
{
    m_regles = new map<string, RuleContainer*>();
    m_incompatibilite = new vector<string>();
    m_name = name;
}

Ajout::~Ajout()
{
    delete m_regles;
    delete m_incompatibilite;
}

RuleContainer * Ajout::getRegle(string ruleName) {
    if(m_regles->find(ruleName) == m_regles->end()) {
        throw std::invalid_argument(string("unknown rules asked : [") + ruleName + string("] from Ajout ") + m_name);
    }
    return m_regles->at(ruleName);
}

map<string,RuleContainer*> * Ajout::getRegles() {
    return m_regles;
}

void Ajout::addRegle(RuleContainer * rule) {
    m_regles->insert(pair<string,RuleContainer*>(rule->getRuleName(), rule));
}

void Ajout::addIncompatibilite(string incompatibilite) {
    m_incompatibilite->push_back(incompatibilite);
}
