#ifndef RULECONTAINER_HPP
#define RULECONTAINER_HPP

#include <iostream>
#include <vector>

class RuleContainer {

public:

    RuleContainer(std::string name, int value, int turnEffect, std::vector<std::string> * conditions);
    virtual ~RuleContainer();

    void setTemporatyValue(int value, int turnEffect);
    int getCurrentValue();
    bool isEffective();

private:

    std::string m_ruleName;
    std::vector<std::string> * m_conditions;

    //-1 always, 0 off, x to decrease
    int m_turnEffect;
    int m_value;

    //-1 always, 0 off, x to decrease
    int m_temporaryTurnEffect;
    int m_temporaryValue;


};

#endif // RULECONTAINER_HPP
