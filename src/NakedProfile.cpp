#include "NakedProfile.hpp"

using namespace std;
using Json = nlohmann::json;

NakedProfile::NakedProfile()
{
    //ctor
}

NakedProfile::~NakedProfile()
{
    //dtor
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
}
