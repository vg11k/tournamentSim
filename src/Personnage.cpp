#include "Personnage.hpp"

using namespace std;
using Json = nlohmann::json;


Personnage::Personnage(Json jsonContainer)
{
    m_type = jsonContainer[Constants::STRING_NAME_TYPE_PROFIL];
    m_name = jsonContainer[Constants::STRING_NAME_NOM_PERSONNAGE];
}

/*Personnage::Personnage(const Personnage & p) {
    setType(p.getType());
    setName(p.getName());
    setCapaciteCombat(p.getCapaciteCombat());
    setCapaciteTir(p.getCapaciteTir());
    setForce(p.getForce());
    setEndurance(p.getEndurance());
    setPointsDeVie(p.getPointsDeVie());
    setInitiative(p.getInitiative());
    setAttaques(p.getAttaques());
    setCommandement(p.getCommandement());
    setPrix(p.getPrix());
    setFaction(p.getFaction());
}*/


Personnage::~Personnage()
{
    //dtor
}

/*void Personnage::updateBaseContent() {

    ProfileManager * manager = ProfileManager::getMe();
    NakedProfile nakedProfile = manager->getProfile(getType());

    setCapaciteCombat(nakedProfile.getCapaciteCombat());
    setCapaciteTir(nakedProfile.getCapaciteTir());
    setForce(nakedProfile.getForce());
    setEndurance(nakedProfile.getEndurance());
    setPointsDeVie(nakedProfile.getPointsDeVie());
    setInitiative(nakedProfile.getInitiative());
    setAttaques(nakedProfile.getAttaques());
    setCommandement(nakedProfile.getCommandement());
    setPrix(nakedProfile.getPrix());
    setFaction(nakedProfile.getFaction());
}*/

void Personnage::sePresenter() {
    cout << "Hello je suis " << m_name << " un " << m_type << endl;
}

Duelliste * Personnage::getDuelliste() {
    ProfileManager * manager = ProfileManager::getMe();
    NakedProfile nakedProfile = manager->getProfile(getType());

    Duelliste * duelliste = new Duelliste(&nakedProfile, this);
    return duelliste;
}

void to_json(Json& j, const Personnage& p)
{
    j = Json{
        {Constants::STRING_NAME_TYPE_PROFIL, p.getType()},
        {Constants::STRING_NAME_NOM_PERSONNAGE, p.getName()}
    };
}

void from_json(const Json& j, Personnage& p)
{
    p.setType(j.at(Constants::STRING_NAME_TYPE_PROFIL).get<std::string>());
    p.setName(j.at(Constants::STRING_NAME_NOM_PERSONNAGE).get<std::string>());
    //p.updateBaseContent();
}



