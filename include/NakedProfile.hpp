#ifndef NAKEDPROFILE_H
#define NAKEDPROFILE_H

#include <iostream>

#include <nlohmann/json.hpp>
#include "Constants.h"


class NakedProfile
{
public:
    NakedProfile();
    virtual ~NakedProfile();

    void setType(std::string s);
    std::string getType() const;
    void setCapaciteCombat(int i);
    int getCapaciteCombat() const;
    void setCapaciteTir(int i);
    int getCapaciteTir() const;
    void setForce(int i);
    int getForce() const;
    void setEndurance(int i);
    int getEndurance() const;
    void setPointsDeVie(int i);
    int getPointsDeVie() const;
    void setInitiative(int i);
    int getInitiative() const;
    void setAttaques(int i);
    int getAttaques() const;
    void setCommandement(int i);
    int getCommandement() const;
    void setPrix(int i);
    int getPrix() const;
    void setFaction(std::string s);
    std::string getFaction() const;

protected:



private:

    std::string m_type;
    int m_capacite_combat;
    int m_capacite_tir;
    int m_force;
    int m_endurance;
    int m_points_de_vie;
    int m_initiative;
    int m_attaques;
    int m_commandement;
    int m_prix;
    std::string m_faction;
};

void to_json(nlohmann::json& j, const NakedProfile& p);
void from_json(const nlohmann::json& j, NakedProfile& p);

inline void NakedProfile::setType(std::string s) {
    m_type = s;
}
inline std::string NakedProfile::getType() const {
    return m_type;
}
inline void NakedProfile::setCapaciteCombat(int i) {
    m_capacite_combat = i;
}
inline int NakedProfile::getCapaciteCombat() const {
    return m_capacite_combat;
}
inline void NakedProfile::setCapaciteTir(int i) {
    m_capacite_tir = i;
}
inline int NakedProfile::getCapaciteTir() const {
    return m_capacite_tir;
}
inline void NakedProfile::setForce(int i) {
    m_force = i;
}
inline int NakedProfile::getForce() const {
    return m_force;
}
inline void NakedProfile::setEndurance(int i) {
    m_endurance = i;
    }
inline int NakedProfile::getEndurance() const {
    return m_endurance;
}
inline void NakedProfile::setPointsDeVie(int i) {
    m_points_de_vie = i;
}
inline int NakedProfile::getPointsDeVie() const {
    return m_points_de_vie;
}
inline void NakedProfile::setInitiative(int i) {
    m_initiative = i;
}
inline int NakedProfile::getInitiative() const {
    return m_initiative;
}
inline void NakedProfile::setAttaques(int i) {
    m_attaques = i;
}
inline int NakedProfile::getAttaques() const {
    return m_attaques;
}
inline void NakedProfile::setCommandement(int i) {
    m_commandement = i;
}
inline int NakedProfile::getCommandement() const {
    return m_commandement;
}
inline void NakedProfile::setPrix(int i) {
    m_prix = i;
}
inline int NakedProfile::getPrix() const {
    return m_prix;
}
inline void NakedProfile::setFaction(std::string s) {
    m_faction = s;
}
inline std::string NakedProfile::getFaction() const {
    return m_faction;
}


#endif // NAKEDPROFILE_H