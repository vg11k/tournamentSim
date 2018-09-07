#include "Duelliste.hpp"

Duelliste::Duelliste(NakedProfile* profil, Personnage* personnage)
{

    setNakedProfile(profil);
    setPersonnage(personnage);
    setCapaciteCombat(profil->getCapaciteCombat());
    setCapaciteTir(profil->getCapaciteTir());
    setForce(profil->getForce());
    setEndurance(profil->getEndurance());
    setPointsDeVie(profil->getPointsDeVie());
    setInitiative(profil->getInitiative());
    setAttaques(profil->getAttaques());
    setCommandement(profil->getCommandement());
    setPrix(profil->getPrix());
    //setFaction(profil->getFaction());
    setFaction("toto");
    setCurrentHP(getPointsDeVie());

    std::cout << "CC duelliste " << getCapaciteCombat() << std::endl;
}

Duelliste::~Duelliste()
{
    //dtor
}



void Duelliste::setPersonnage(Personnage * p)
{
    m_personnage = p;
}
Personnage * Duelliste::getPersonnage() const
{
    return m_personnage;
}
void Duelliste::setNakedProfile(NakedProfile * p)
{
    m_nakedProfile = p;
}
NakedProfile * Duelliste::getNakedProfile() const
{
    return m_nakedProfile;
}

std::string Duelliste::getName() const
{
    return m_personnage->getName();
}
std::string Duelliste::getType() const
{
    return m_nakedProfile->getType();
}

void Duelliste::removeHP(int i) {
    m_currentHP -= i;
}

void Duelliste::sePresenter() {
    std::cout << "J'ai " << m_capacite_combat << " de CC et " << m_force << " en force" << std::endl;
}
