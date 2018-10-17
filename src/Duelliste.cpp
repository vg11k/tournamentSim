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

    m_rules = new RuleContainers();
    completer(profil->getRegles(), personnage->getOptions(), personnage->getAchats());
    setFaction(profil->getFaction());
    setCurrentHP(getPointsDeVie());

    m_quickAccess = new std::map<std::string,int>();

    FactoryRules ruleFactory;

    std::map<std::string,int> * tmpMap = profil->getRegles();
    for(std::map<std::string,int>::iterator it = tmpMap->begin(); it != tmpMap->end(); ++it)
    {
        string key = it->first; // accede à la clé
        int value = it->second; // accede à la valeur
        RuleContainer * rule = ruleFactory.getSubRules(key, value);
        m_rules->insert(pair<string,RuleContainer*>(key, rule));
    }

    FactoryAjout factory;


    m_achats = new std::vector<Item*>();
    vector<string> * achats = personnage->getAchats();

    for(vector<string>::iterator it = achats->begin(); it != achats->end(); ++it) {
        m_achats->push_back((Item*)factory.Create(*it));
    }


    m_regeneration = 999;
    m_invulnerable = 999;
    m_charge = true;
}

Duelliste::~Duelliste()
{
    delete m_quickAccess;
    delete m_achats;
    delete m_rules;
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
    return checkIfRuleExist(Constants::STRING_VALUE_REGLE_REGENERATION, true);
}

bool Duelliste::checkIfRuleExist(string ruleName, bool updateQuickAccess) {
    bool found = false;
    int value = -1;
    if(m_rules->find(ruleName) != m_rules->end()) {
        found =  true;
        value = m_rules->at(ruleName)->getCurrentValue();
    }

    for(vector<Item*>::iterator it = m_achats->begin(); it != m_achats->end(); ++it)
    {
        Item * itemFound = *it;
        if(itemFound->getRegles()->find(ruleName) != itemFound->getRegles()->end()) {
            found =  true;
            value = itemFound->getRegle(ruleName)->getCurrentValue();
        }
    }
    if(updateQuickAccess) {
        if(found) {
            m_quickAccess->insert(pair<string,int>(ruleName, value));
        }
        else if(m_quickAccess->find(ruleName) != m_quickAccess->end()){
            m_quickAccess->erase(ruleName);
        }
    }
    return found;
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

    for(map<string,int>::iterator it = getNakedProfile()->getRegles()->begin() ; it!= getNakedProfile()->getRegles()->end() ; ++it)
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


void Duelliste::completer(std::map<std::string,int> * reglesProfil,
                          std::vector<std::string> * nameOptions,
                          std::vector<std::string> * nameAchats) {
    //creer map des regles du profil nu & completer avec les achats et option du personnage
    FactoryRules factory;

    for(std::map<std::string,int>::iterator it = reglesProfil->begin(); it != reglesProfil->end(); ++it) {
        RuleContainer * rule = factory.getSubRules(it->first, it->second);
        m_rules->insert(pair<string,RuleContainer*>(it->first, rule));
    }
}

int Duelliste::getInitiative() const {
    int initiative = m_initiative;
    initiative = genericGetter(initiative, Constants::STRING_NAME_REGLE_AMELIORATION_INITIATIVE, Constants::STRING_NAME_REGLE_CHANGEMENT_INITIATIVE);

    /*int changementInit = -1;
    int ameliorationInit = 0;

    //checker les passifs de base et options du profil
    RuleContainers::iterator it = m_rules->find(Constants::STRING_NAME_REGLE_AMELIORATION_INITIATIVE);
    if(it != m_rules->end()) {
        ameliorationInit += it->second->getCurrentValue();
    }

    it = m_rules->find(Constants::STRING_NAME_REGLE_CHANGEMENT_INITIATIVE);
    if(it != m_rules->end()) {
        changementInit = it->second->getCurrentValue();
    }

    //checker les items du personnage
    for(std::vector<Item*>::iterator itemIt = m_achats->begin(); itemIt != m_achats->end(); ++itemIt) {

        Item * item = *itemIt;
        RuleContainers * reglesItem = item->getRegles();

        it = reglesItem->find(Constants::STRING_NAME_REGLE_AMELIORATION_INITIATIVE);
        if(it != reglesItem->end()) {
            ameliorationInit += it->second->getCurrentValue();
        }

        it = reglesItem->find(Constants::STRING_NAME_REGLE_CHANGEMENT_INITIATIVE);
        if(it != reglesItem->end()) {
            changementInit = it->second->getCurrentValue();
        }
    }
    if(changementInit != -1) {
        initiative = changementInit;
    }
    else {
        initiative += ameliorationInit;
    }
    return initiative;*/
}


int Duelliste::getForce() const {
    int force = m_force;
    force = genericGetter(force, Constants::STRING_NAME_REGLE_AMELIORATION_FORCE, Constants::STRING_NAME_REGLE_CHANGEMENT_FORCE);

    /*
    int changementForce = -1;
    int ameliorationForce = 0;

    //checker les passifs de base et options du profil
    RuleContainers::iterator it = m_rules->find(Constants::STRING_NAME_REGLE_AMELIORATION_FORCE);
    if(it != m_rules->end()) {
        ameliorationForce += it->second->getCurrentValue();
    }

    it = m_rules->find(Constants::STRING_NAME_REGLE_CHANGEMENT_FORCE);
    if(it != m_rules->end()) {
        changementForce = it->second->getCurrentValue();
    }

    //checker les items du personnage
    for(std::vector<Item*>::iterator itemIt = m_achats->begin(); itemIt != m_achats->end(); ++itemIt) {

        Item * item = *itemIt;
        RuleContainers * reglesItem = item->getRegles();

        it = reglesItem->find(Constants::STRING_NAME_REGLE_AMELIORATION_FORCE);
        if(it != reglesItem->end()) {
            ameliorationForce += it->second->getCurrentValue();
        }

        it = reglesItem->find(Constants::STRING_NAME_REGLE_CHANGEMENT_FORCE);
        if(it != reglesItem->end()) {
            changementForce = it->second->getCurrentValue();
        }
    }
    if(changementForce != -1) {
        force = changementForce;
    }
    else {
        force += ameliorationForce;
    }*/
    return force;
}

int Duelliste::getAttaques() const {
    int attaques = m_attaques;
    attaques = genericGetter(attaques, Constants::STRING_NAME_REGLE_AMELIORATION_ATTAQUES, Constants::STRING_NAME_REGLE_CHANGEMENT_ATTAQUES);
    return m_attaques;
}

int Duelliste::genericGetter(int initialValue, const string ameliorationStringName, const string changementStringName) const {
    int result = initialValue;

    int changementValue = -1;
    int ameliorationValue = 0;

    //checker les passifs de base et options du profil
    RuleContainers::iterator it = m_rules->find(ameliorationStringName);
    if(it != m_rules->end()) {
        ameliorationValue += it->second->getCurrentValue();
    }

    it = m_rules->find(changementStringName);
    if(it != m_rules->end()) {
        changementValue = it->second->getCurrentValue();
    }

    //checker les items du personnage
    for(std::vector<Item*>::iterator itemIt = m_achats->begin(); itemIt != m_achats->end(); ++itemIt) {

        Item * item = *itemIt;
        RuleContainers * reglesItem = item->getRegles();

        it = reglesItem->find(ameliorationStringName);
        if(it != reglesItem->end()) {
            ameliorationValue += it->second->getCurrentValue();
        }

        it = reglesItem->find(changementStringName);
        if(it != reglesItem->end()) {
            changementValue = it->second->getCurrentValue();
        }
    }
    if(changementValue != -1) {
        result = changementValue;
    }
    else {
        result += ameliorationValue;
    }
    return result;
}
