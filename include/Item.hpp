#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "Ajout.hpp"

class Item : public Ajout
{
    public:
        Item();
        virtual ~Item();

    protected:

    private:

        std::string m_slot;
        bool m_magique;
};

#endif // ITEM_H
