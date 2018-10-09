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

    m_rules = new Rules();
    completer(profil->getRegles(), personnage->getAjout());
    setCurrentHP(getPointsDeVie());

    m_regeneration = 999;
    m_invulnerable = 999;
    m_charge = true;
}

Duelliste::~Duelliste()
{
    //dtor
}


/*//////////////////////
// get            set //
//////////////////////*/

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

/*/////////////////////
//                  //
////////////////////*/

int Duelliste::getBlessuresMultiples(Duelliste * cible, int roundCounter, bool tourDeCharge) {
    //TODO
    return 1;
}

void Duelliste::removeHP(int i) {
    m_currentHP -= i;
}

void Duelliste::sePresenter() {
    std::cout << "J'ai " << m_capacite_combat << " de CC et " << m_force << " en force" << std::endl;
    std::cout << "Voici mes regles : ";

    for(Rules::iterator it = getNakedProfile()->getRegles()->begin() ; it!= getNakedProfile()->getRegles()->end() ; ++it)
    {
            std::cout << it->first  << " ";
    }
    std::cout << std::endl;
}

bool Duelliste::charge() {
    return m_charge;
}

void Duelliste::updateStatus() {
    m_charge = false;
    //maj de la map d'effets temporaires comme la peur
}

void Duelliste::completer(std::map<std::string,int> * reglesProfil, std::vector<std::string> * ajoutNames) {
    //creer map des regles du profil nu & completer avec les achats et option du personnage

    for(Rules::iterator it = reglesProfil->begin(); it != reglesProfil->end(); ++it) {
        m_rules->insert(pair<string,int>(it->first, it->second));
    }

    ProfileManager * manager = ProfileManager::getMe();
    for(int i = 0; i < ajoutNames->size(); i++) {
        Ajout * ajout =  manager->getAjout(ajoutNames->at(i));
    }
}
