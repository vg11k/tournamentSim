#include "RuleContainer.hpp"

RuleContainer::RuleContainer(std::string name, int value, int turnEffect, std::vector<std::string> * conditions) {
    m_ruleName = name;
    m_value = value;
    m_turnEffect = turnEffect;
    m_conditions = conditions;

    m_temporaryTurnEffect = 0;
    m_temporaryValue = 0;
}

void RuleContainer::setTemporatyValue(int value, int turnEffect)
{
    m_temporaryValue = value;
    m_temporaryTurnEffect = turnEffect;
}

int RuleContainer::getCurrentValue()
{
    if(m_temporaryTurnEffect != 0) {
        return m_temporaryValue;
    }
    else if(m_turnEffect != 0) {
        return m_value;
    }
}

bool RuleContainer::isEffective() {
    if(m_turnEffect == 0 || (m_turnEffect == 0 && m_temporaryTurnEffect == 0)) {
        return false;
    }
    return true;
}
