#ifndef AJOUT_H
#define AJOUT_H

#include <iostream>
#include <vector>
#include <map>

#include "Amelioration.hpp"
#include "RuleContainer.hpp"


class Ajout
{
    public:
        Ajout();
        virtual ~Ajout();

        RuleContainer * getRegle(std::string ruleName);
        std::map<std::string, RuleContainer*> * getRegles();

    protected:

    private:

        std::string m_name;

        //NakedProfile or Ajout or RuleContainer name
        std::vector<std::string> * m_profilEligible;
        std::vector<std::string> * m_incompatibilite;
        std::vector<std::string> * m_necessite;

        std::vector<Amelioration> * m_amelioration;
        std::map<std::string, RuleContainer*> * m_regles;
};



#endif // AJOUT_H
