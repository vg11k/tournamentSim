#include "NakedProfile.hpp"

using namespace std;
using Json = nlohmann::json;

NakedProfile::NakedProfile()
{
    m_winningStats = new map<string, int>();
    m_losingStats = new map<string, int>();
    m_regles = new map<string, int>();
    m_catalogueAchats = new map<string, int>();
}

NakedProfile::~NakedProfile()
{
    delete m_winningStats;
    delete m_losingStats;
    delete m_regles;
    delete m_catalogueAchats;
}

void NakedProfile::retrieveFrom(NakedProfile & original)
{
    setType(original.getType());
    setCapaciteCombat(original.getCapaciteCombat());
    setCapaciteTir(original.getCapaciteTir());
    setForce(original.getForce());
    setEndurance(original.getEndurance());
    setPointsDeVie(original.getPointsDeVie());
    setInitiative(original.getInitiative());
    setAttaques(original.getAttaques());
    setCommandement(original.getCommandement());
    setPrix(original.getPrix());
    setRegles(original.getRegles());
}

void NakedProfile::setRegles(map<string, int> * r)
{
    m_regles->clear();
    for(Rules::iterator it = r->begin(); it != r->end(); ++it)
    {
        string key = it->first; // accede à la clé
        int value = it->second; // accede à la valeur
        m_regles->insert(pair<string,int>(key, value));
    }

}

void NakedProfile::addRegle(nlohmann::json& j) {
    string name = j[Constants::STRING_NAME_NOM_REGLE];
    int value = j[Constants::STRING_NAME_VALEUR_REGLE];
    m_regles->insert(pair<string,int>(name, value));
}

void NakedProfile::addAchatPossible(nlohmann::json& j) {
    string name = j[Constants::STRING_NAME_NOM_ACHAT];
    int prix = j[Constants::STRING_NAME_VALEUR_ACHATS];
    m_catalogueAchats->insert(pair<string,int>(name, prix));
}

void NakedProfile::setRegles(std::vector<nlohmann::json>& j)
{
    m_regles->clear();

    std::cout << j.size() << endl;
    for(unsigned int i = 0; i < j.size(); i++)
    {
        Json regle = j[i];
    }
}

//renvoie une copie
std::map<std::string,int> * NakedProfile::getRegles() const
{
    /*map<string, int> tmpMap;

    // pour parcourir toutes les paires de la map
    for(Rules::iterator it=m_regles->begin() ; it!=m_regles->end() ; ++it)
    {
        string key = it->first; // accede a la clé
        int value = it->second; // accede a la valeur
        tmpMap[key] = value;
    }*/

    return m_regles;
}

void NakedProfile::incrementWinningStats(std::string profileType)
{
    map<string, int>::iterator  it=  m_winningStats->find(profileType);
    if( it == m_winningStats->end() )
    {
        m_winningStats->insert(pair<string,int>(profileType, 0));
    }
    it->second++;
}

void NakedProfile::incrementLosingStats(std::string profileType)
{
    map<string, int>::iterator  it=  m_losingStats->find(profileType);
    if( it == m_losingStats->end() )
    {
        m_losingStats->insert(pair<string,int>(profileType, 0));
    }
    it->second++;
}

int NakedProfile::getWiningStats(std::string profileType)
{
    map<string, int>::iterator  it=  m_winningStats->find(profileType);
    if( it == m_winningStats->end() )
    {
        return 0;
    }
    return it->second;
}

int NakedProfile::getLosingStats(std::string profileType)
{
    map<string, int>::iterator  it=  m_losingStats->find(profileType);
    if( it == m_losingStats->end() )
    {
        return 0;
    }
    return it->second;
}

void to_json(Json& j, const NakedProfile& p)
{
    j = Json
    {
        {Constants::STRING_NAME_TYPE_PROFIL, p.getType()},
        {Constants::STRING_NAME_CHARACTERISTIC_CAPACITE_COMBAT, p.getCapaciteCombat()},
        {Constants::STRING_NAME_CHARACTERISTIC_CAPACITE_TIR, p.getCapaciteTir()},
        {Constants::STRING_NAME_CHARACTERISTIC_FORCE, p.getForce()},
        {Constants::STRING_NAME_CHARACTERISTIC_ENDURANCE, p.getEndurance()},
        {Constants::STRING_NAME_CHARACTERISTIC_INITIATIVE, p.getInitiative()},
        {Constants::STRING_NAME_CHARACTERISTIC_ATTAQUES, p.getAttaques()},
        {Constants::STRING_NAME_CHARACTERISTIC_POINTS_DE_VIE, p.getPointsDeVie()},
        {Constants::STRING_NAME_CHARACTERISTIC_COMMANDEMENT, p.getCommandement()},
        {Constants::STRING_NAME_CHARACTERISTIC_PRIX, p.getPrix()}
        //{Constants::STRING_NAME_REGLES, p.getRegles()}
    };
}

void from_json(const Json& j, NakedProfile& p)
{
    p.setType(j.at(Constants::STRING_NAME_TYPE_PROFIL).get<std::string>());
    p.setCapaciteCombat(j.at(Constants::STRING_NAME_CHARACTERISTIC_CAPACITE_COMBAT).get<int>());
    p.setCapaciteTir(j.at(Constants::STRING_NAME_CHARACTERISTIC_CAPACITE_TIR).get<int>());
    p.setForce(j.at(Constants::STRING_NAME_CHARACTERISTIC_FORCE).get<int>());
    p.setEndurance(j.at(Constants::STRING_NAME_CHARACTERISTIC_ENDURANCE).get<int>());
    p.setInitiative(j.at(Constants::STRING_NAME_CHARACTERISTIC_INITIATIVE).get<int>());
    p.setAttaques(j.at(Constants::STRING_NAME_CHARACTERISTIC_ATTAQUES).get<int>());
    p.setPointsDeVie(j.at(Constants::STRING_NAME_CHARACTERISTIC_POINTS_DE_VIE).get<int>());
    p.setCommandement(j.at(Constants::STRING_NAME_CHARACTERISTIC_COMMANDEMENT).get<int>());
    p.setPrix(j.at(Constants::STRING_NAME_CHARACTERISTIC_PRIX).get<int>());

    nlohmann::json data = j[Constants::STRING_NAME_REGLES];
    //p.setRegles(j[Constants::STRING_NAME_REGLES]);

    for(unsigned int i = 0; i < data.size(); i++)
    {
        p.addRegle(data[i]);
    }

    data = j[Constants::STRING_NAME_ACHATS];
    for(unsigned int i = 0; i < data.size(); i++)
    {
        p.addAchatPossible(data[i]);
    }

    /*m_regles->clear();
    for ( Json::iterator it = j.begin(); it != j.end(); ++it) {
      //std::cout << *it << '\n';
      m_regles->insert(pair<string,int>(it.key(), it.value()));
    }*/
    //p.setRegles(j[Constants::STRING_NAME_REGLES]);
}
