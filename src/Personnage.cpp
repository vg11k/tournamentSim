#include "Personnage.hpp"

using namespace std;
using Json = nlohmann::json;

Personnage::Personnage() {
    m_achats = new vector<string>();
    m_options = new vector<string>();
}

Personnage::Personnage(Json jsonContainer)
{
    m_type = jsonContainer[Constants::STRING_NAME_TYPE_PROFIL];
    m_name = jsonContainer[Constants::STRING_NAME_NOM_PERSONNAGE];

    m_achats = new vector<string>();
    m_options = new vector<string>();

    nlohmann::json data = jsonContainer[Constants::STRING_NAME_ACHATS];
    for(unsigned int i = 0; i < data.size(); i++)
    {

        string nomAchat = data[i];
        addAchat(nomAchat);
    }

    data = jsonContainer[Constants::STRING_NAME_OPTIONS];
    for(unsigned int i = 0; i < data.size(); i++)
    {
        string nomOption = data[i];
        addOption(nomOption);
    }
}

void Personnage::recopy(Personnage &p) {
    m_type = p.getType();
    m_name = p.getName();

    std::vector<std::string> * achats = p.getAchats();
    for(unsigned int i = 0; i < achats->size(); i++) {
        m_achats->push_back(achats->at(i));
    }

    std::vector<std::string> * options = p.m_options;
    for(unsigned int i = 0; i < options->size(); i++) {
        m_options->push_back(options->at(i));
    }
}

Personnage::~Personnage()
{
    delete m_achats;
    delete m_options;
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
    /*
    p.setType(j.at(Constants::STRING_NAME_TYPE_PROFIL).get<std::string>());
    p.setName(j.at(Constants::STRING_NAME_NOM_PERSONNAGE).get<std::string>());

    nlohmann::json data = j[Constants::STRING_NAME_ACHATS];
    for(unsigned int i = 0; i < data.size(); i++)
    {

        string nomAchat = data[i];
        cout << "ajout de l'achat " << nomAchat <<endl;
        p.addAchat(nomAchat);
    }

    data = j[Constants::STRING_NAME_OPTIONS];
    for(unsigned int i = 0; i < data.size(); i++)
    {
        string nomOption = data[i];
        cout << "ajout de l'option " << nomOption <<endl;
        p.addOption(nomOption);
    }
    */
}

std::vector<std::string> * Personnage::getAjout() {
    std::vector<std::string> * ajouts = new std::vector<std::string>();
    ajouts->insert( ajouts->end(), m_achats->begin(), m_achats->end() );
    ajouts->insert( ajouts->end(), m_options->begin(), m_options->end() );
    return ajouts;
}

void Personnage::addAchat(const string nomAchat) {
    m_achats->push_back(nomAchat);
}

void Personnage::addOption(const string nomOption) {
    m_options->push_back(nomOption);
}

