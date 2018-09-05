#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <nlohmann/json.hpp>
#include "Constants.h"
#include "ProfileManager.hpp"


class Personnage
{
public:
    Personnage() {};
    Personnage(const Personnage & p);
    Personnage(nlohmann::json jsonContainer);
    virtual ~Personnage();

    void sePresenter();
    void updateBaseContent();

    std::string getType() const;
    void setType(std::string s);
    std::string getName() const;
    void setName(std::string s);
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

    Personnage * getClone();

protected:

    std::string m_name;

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

private:
};

void to_json(nlohmann::json& j, const Personnage& p);
void from_json(const nlohmann::json& j, Personnage& p);

inline std::string Personnage::getName() const
{
    return m_name;
}

inline void Personnage::setName(std::string s)
{
    m_name = s;
}

inline void Personnage::setType(std::string s) {
    m_type = s;
}
inline std::string Personnage::getType() const {
    return m_type;
}
inline void Personnage::setCapaciteCombat(int i) {
    m_capacite_combat = i;
}
inline int Personnage::getCapaciteCombat() const {
    return m_capacite_combat;
}
inline void Personnage::setCapaciteTir(int i) {
    m_capacite_tir = i;
}
inline int Personnage::getCapaciteTir() const {
    return m_capacite_tir;
}
inline void Personnage::setForce(int i) {
    m_force = i;
}
inline int Personnage::getForce() const {
    return m_force;
}
inline void Personnage::setEndurance(int i) {
    m_endurance = i;
    }
inline int Personnage::getEndurance() const {
    return m_endurance;
}
inline void Personnage::setPointsDeVie(int i) {
    m_points_de_vie = i;
}
inline int Personnage::getPointsDeVie() const {
    return m_points_de_vie;
}
inline void Personnage::setInitiative(int i) {
    m_initiative = i;
}
inline int Personnage::getInitiative() const {
    return m_initiative;
}
inline void Personnage::setAttaques(int i) {
    m_attaques = i;
}
inline int Personnage::getAttaques() const {
    return m_attaques;
}
inline void Personnage::setCommandement(int i) {
    m_commandement = i;
}
inline int Personnage::getCommandement() const {
    return m_commandement;
}
inline void Personnage::setPrix(int i) {
    m_prix = i;
}
inline int Personnage::getPrix() const {
    return m_prix;
}
inline void Personnage::setFaction(std::string s) {
    m_faction = s;
}
inline std::string Personnage::getFaction() const {
    return m_faction;
}



#endif // PERSONNAGE_H
