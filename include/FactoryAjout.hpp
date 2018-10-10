#ifndef FACTORYAJOUT_HPP
#define FACTORYAJOUT_HPP

#include <map>
#include <string>

#include "Constants.h"
#include "Ajout.hpp"
#include "Item.hpp"
#include "Option.hpp"

class FactoryAjout
{
    public:
        FactoryAjout();
        virtual ~FactoryAjout();

        //Fonction qui associe clé <=> prototype
        static void Register(const std::string& key,Ajout* obj);

        //Celle qui va créer les objets
        Ajout* Create(const std::string& key) const;

        void initiate();

    protected:

    private:

        static std::map<std::string,Ajout*> * m_catalogue;
};

#endif // FACTORYAJOUT_HPP
