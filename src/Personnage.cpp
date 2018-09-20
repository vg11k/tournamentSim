#include "Personnage.hpp"

using namespace std;
using Json = nlohmann::json;


Personnage::Personnage(Json jsonContainer)
{
    m_type = jsonContainer[Constants::STRING_NAME_TYPE_PROFIL];
    m_name = jsonContainer[Constants::STRING_NAME_NOM_PERSONNAGE];
}

Personnage::~Personnage()
{
    //dtor
}

void Personnage::sePresenter() {
    cout << "Hello je suis " << m_name << " un " << m_type << endl;
}

Duelliste * Personnage::getDuelliste() {

    ProfileManager * manager = ProfileManager::getMe();
    NakedProfile * nakedProfile = manager->getProfile(getType());
    Duelliste * duelliste = new Duelliste(nakedProfile, this);
    duelliste->setFaction(nakedProfile->getFaction());
    return duelliste;
}

bool Personnage::areYouValid() {
    //TODO
    return true;
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
}

std::vector<std::string> * Personnage::getAjout() {
    return NULL;
}



