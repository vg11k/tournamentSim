#ifndef AJOUT_H
#define AJOUT_H

#include <iostream>
#include <vector>
#include <map>

#include "RuleContainer.hpp"


class Ajout
{
    public:
        Ajout(std::string name);
        virtual ~Ajout();
        virtual Ajout* Clone() const  = 0;

        RuleContainer * getRegle(std::string ruleName);
        void addRegle(RuleContainer * rule);
        void addIncompatibilite(std::string incompatibilite);
        std::map<std::string, RuleContainer*> * getRegles();

    protected:

    private:

        std::string m_name;

        //NakedProfile or Ajout or RuleContainer name
        std::vector<std::string> * m_profilEligible;
        std::vector<std::string> * m_incompatibilite;
        std::vector<std::string> * m_necessite;

        std::map<std::string, RuleContainer*> * m_regles;
};



#endif // AJOUT_H
