#ifndef AJOUT_H
#define AJOUT_H

#include <iostream>
#include <vector>

#include "Amelioration.hpp"
#include "RuleContainer.hpp"


class Ajout
{
    public:
        Ajout();
        virtual ~Ajout();

    protected:

    private:

        std::string m_name;

        //NakedProfile or Ajout or RuleContainer name
        std::vector<std::string> * m_profilEligible;
        std::vector<std::string> * m_incompatibilite;
        std::vector<std::string> * m_necessite;

        std::vector<Amelioration> * m_amelioration;
        std::vector<RuleContainer> * m_regles;
};

#endif // AJOUT_H
