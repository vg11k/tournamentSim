#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <map>

#include "Ajout.hpp"


class Option : public Ajout
{
    public:
        Option(std::string name);
        virtual ~Option();
        Ajout * Clone() const;

    protected:

    private:
        int m_prix;
        std::map<std::string,int> m_achatsAdditionnels;
};

#endif // OPTION_H
