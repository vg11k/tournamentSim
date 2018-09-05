#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <nlohmann/json.hpp>
#include "Constants.h"


class Personnage
{
public:
    Personnage() {};
    Personnage(nlohmann::json jsonContainer);
    virtual ~Personnage();

    void sePresenter();

    std::string getType() const;
    void setType(std::string s);

    std::string getName() const;
    void setName(std::string s);

protected:

    std::string m_type;
    /*int m_capacite_combat;
    int m_capacite_tir;
    int m_force;
    int m_endurance;
    int m_points_de_vie;
    int m_initiative;
    int m_attaques;
    int m_commandement;
    int m_prix;*/
    std::string m_name;
    //std::string m_faction;

private:
};

void to_json(nlohmann::json& j, const Personnage& p);
void from_json(const nlohmann::json& j, Personnage& p);

inline std::string Personnage::getType() const
{
    return m_type;
}

inline void Personnage::setType(std::string s)
{
    m_type = s;
}

inline std::string Personnage::getName() const
{
    return m_name;
}

inline void Personnage::setName(std::string s)
{
    m_name = s;
}




#endif // PERSONNAGE_H
