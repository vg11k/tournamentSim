#ifndef DUELLISTE_H
#define DUELLISTE_H

#include <iostream>

#include "Personnage.hpp"
#include "NakedProfile.hpp"
#include "Ajout.hpp"

class Personnage;

class Duelliste
{
public:
    Duelliste(NakedProfile * profile, Personnage * personnage);
    virtual ~Duelliste();

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

    void setPersonnage(Personnage * p);
    void setNakedProfile(NakedProfile * p);
    Personnage * getPersonnage() const;
    NakedProfile * getNakedProfile() const;

    void removeHP(int i);
    int getCurrentHP() const;
    void setCurrentHP(int i);

    void updateStatus();
    bool charge();

    int getBlessuresMultiples(Duelliste * cible, int roundCounter, bool tourDeCharge);

    bool utiliseAttaquesEnflammees();
    bool utiliseAttaquesDivines();

    bool beneficieRegeneration();
    bool beneficieInvulnerabilite();

    int getPerforant();

    int getSauvegardeArmure();
    int getRegeneration();
    int getSauvegardeInvulnerable();

    bool checkIfRuleExist(std::string ruleName, bool updateQuickAccess);

    void sePresenter();
    void completer(std::map<std::string,int> * reglesProfil, std::vector<std::string> * achats);
    typedef std::map<std::string, int>  Rules;

protected:

private:

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

    bool m_charge;

    bool m_utiliseAttaquesEnflammees;
    bool m_utiliseAttaquesDivines;

    int m_perforant;
    int m_armure;
    int m_regeneration;
    int m_invulnerable;

    int m_currentHP;
    Rules * m_rules;

    std::map<std::string, Item*> * m_achats;
    std::map<std::string,int> * m_regles;
    std::map<std::string,int> * m_quickAccess;


    Personnage * m_personnage;
    NakedProfile * m_nakedProfile;
};



inline void Duelliste::setCapaciteCombat(int i) {
    m_capacite_combat = i;
}
inline int Duelliste::getCapaciteCombat() const {
    return m_capacite_combat;
}
inline void Duelliste::setCapaciteTir(int i) {
    m_capacite_tir = i;
}
inline int Duelliste::getCapaciteTir() const {
    return m_capacite_tir;
}
inline void Duelliste::setForce(int i) {
    m_force = i;
}
inline int Duelliste::getForce() const {
    return m_force;
}
inline void Duelliste::setEndurance(int i) {
    m_endurance = i;
    }
inline int Duelliste::getEndurance() const {
    return m_endurance;
}
inline void Duelliste::setPointsDeVie(int i) {
    m_points_de_vie = i;
}
inline int Duelliste::getPointsDeVie() const {
    return m_points_de_vie;
}
inline void Duelliste::setInitiative(int i) {
    m_initiative = i;
}
inline int Duelliste::getInitiative() const {
    return m_initiative;
}
inline void Duelliste::setAttaques(int i) {
    m_attaques = i;
}
inline int Duelliste::getAttaques() const {
    return m_attaques;
}
inline void Duelliste::setCommandement(int i) {
    m_commandement = i;
}
inline int Duelliste::getCommandement() const {
    return m_commandement;
}
inline void Duelliste::setPrix(int i) {
    m_prix = i;
}
inline int Duelliste::getPrix() const {
    return m_prix;
}
inline void Duelliste::setFaction(std::string s) {
    m_faction = s;
}
inline std::string Duelliste::getFaction() const {
    return m_faction;
}
inline int Duelliste::getCurrentHP() const {
    return m_currentHP;
}
inline void Duelliste::setCurrentHP(int i) {
    m_currentHP = i;
}



#endif // DUELLISTE_H
