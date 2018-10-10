#ifndef FACTORYRULES_H
#define FACTORYRULES_H

#include <iostream>
#include <vector>
#include <map>
#include "Constants.h"
#include "RuleContainer.hpp"



class FactoryRules
{
    public:
        FactoryRules();
        virtual ~FactoryRules();

        static void Register(const std::string& key, RuleContainer* obj);
        RuleContainer* Create(const std::string& key) const;

        RuleContainer * getSubRules(std::string vanillaRuleName, int value);

        void initiate();

    protected:

    private:
        static std::map<std::string,RuleContainer*> m_catalogue;
};

#endif // FACTORYRULES_H
