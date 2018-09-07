#include "Duelliste.hpp"

using namespace std;

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

    m_regeneration = 999;
    m_invulnerable = 999;
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

bool Duelliste::utiliseAttaquesEnflammees() {
    return m_utiliseAttaquesEnflammees;
}
bool Duelliste::utiliseAttaquesDivines() {
    return m_utiliseAttaquesDivines;
}

bool Duelliste::beneficieRegeneration() {
    return m_regeneration != 999;
}
bool Duelliste::beneficieInvulnerabilite() {
    return m_invulnerable != 999;
}

int Duelliste::getPerforant() {
    return m_perforant;
}

int Duelliste::getSauvegardeArmure() {
    return m_armure;
}
int Duelliste::getRegeneration() {
    return m_regeneration;
}
int Duelliste::getSauvegardeInvulnerable() {
    return m_invulnerable;
}
