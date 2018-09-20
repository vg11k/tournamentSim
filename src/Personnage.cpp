#include "Personnage.hpp"

using namespace std;
using Json = nlohmann::json;


Personnage::Personnage(Json jsonContainer)
{
    m_items = new vector<string>();
    m_options = new vector<string>();

    m_type = jsonContainer[Constants::STRING_NAME_TYPE_PROFIL];
    m_name = jsonContainer[Constants::STRING_NAME_NOM_PERSONNAGE];


    nlohmann::json data = jsonContainer[Constants::STRING_NAME_ACHATS];
    for(unsigned int i = 0; i < data.size(); i++)
    {
        addItem(data[i]);
    }

    data = jsonContainer[Constants::STRING_NAME_OPTIONS];
    for(unsigned int i = 0; i < data.size(); i++)
    {
        addOption(data[i]);
    }
}

Personnage::Personnage() {
    m_items = new vector<string>();
    m_options = new vector<string>();
}

void Personnage::recopy(Personnage &p) {
    m_type = p.getType();
    m_name = p.getName();

    std::vector<std::string> * items = p.m_items;
    for(unsigned int i = 0; i < m_items->size(); i++) {
        m_items->push_back(items->at(i));
    }

    std::vector<std::string> * options = p.m_options;
    for(unsigned int i = 0; i < m_options->size(); i++) {
        m_options->push_back(options->at(i));
    }
}

Personnage::~Personnage()
{
    delete m_items;
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

void Personnage::addItem(string itemName) {
    m_items->push_back(itemName);
}

void Personnage::addOption(string optionName) {
    m_options->push_back(optionName);
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

    nlohmann::json data = j[Constants::STRING_NAME_ACHATS];
    for(unsigned int i = 0; i < data.size(); i++)
    {
        p.addItem(data[i]);
    }

    data = j[Constants::STRING_NAME_OPTIONS];
    for(unsigned int i = 0; i < data.size(); i++)
    {
        p.addOption(data[i]);
    }
}

std::vector<std::string> * Personnage::getAjout() {
    return NULL;
}



