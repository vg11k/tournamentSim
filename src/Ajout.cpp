#include "Ajout.hpp"

using namespace std;

Ajout::Ajout()
{
    m_regles = new map<string, RuleContainer*>();
}

Ajout::~Ajout()
{
    delete m_regles;
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
