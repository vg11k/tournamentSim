#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <vector>

#include <nlohmann/json.hpp>
#include "Constants.h"
#include "ProfileManager.hpp"
#include "Duelliste.hpp"

class Duelliste;

class Personnage
{
public:

    Personnage(nlohmann::json jsonContainer);
    Personnage();
    virtual ~Personnage();

    void sePresenter();
    void updateBaseContent();


    void recopy(Personnage &p);

    std::string getType() const;
    void setType(std::string s);
    std::string getName() const;
    void setName(std::string s);



    Duelliste * getDuelliste();

    void addItem(std::string itemName);
    void addOption(std::string optionName);

    //achats et options condensees
    std::vector<std::string> * getAjout();

    /*
        check si le perso est "valide"
        ex : un vampire avec une bene imperiale ou un bretonnien avec un item vampire seront invalides
    */
    bool areYouValid();

protected:

    std::string m_name;
    std::string m_type;
    std::vector<std::string> * m_items;
    std::vector<std::string> * m_options;

private:
};

void to_json(nlohmann::json& j, const Personnage& p);
void from_json(const nlohmann::json& j, Personnage& p);

inline std::string Personnage::getName() const
{
    return m_name;
}

inline void Personnage::setName(std::string s)
{
    m_name = s;
}

inline void Personnage::setType(std::string s) {
    m_type = s;
}
inline std::string Personnage::getType() const {
    return m_type;
}


#endif // PERSONNAGE_H
