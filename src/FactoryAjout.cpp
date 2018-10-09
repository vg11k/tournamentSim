#include "FactoryAjout.hpp"

using namespace std;

map<string, Ajout*> FactoryAjout::m_catalogue = map<string, Ajout*>();

FactoryAjout::FactoryAjout()
{
    //ctor
}

FactoryAjout::~FactoryAjout()
{
    //dtor
}

void FactoryAjout::Register(const string & key, Ajout * obj) {
    if(m_catalogue.find(key) == m_catalogue.end()) {
        m_catalogue[key] = obj;
    }
}

Ajout * FactoryAjout::Create(const string& key) const {
    Ajout * tmp = 0;
    map<string, Ajout*>::const_iterator it = m_catalogue.find(key);
    if(it!=m_catalogue.end())
    {
        tmp=((*it).second)->Clone();
    }
    else {
        string s = string("Nom d'ajout a cloner inconnu : ") + key;
        perror ( s.c_str());
    }

    return tmp;
}
