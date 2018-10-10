#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

#include "Ajout.hpp"

class Item : public Ajout
{
    public:
        Item(std::string name, std::vector<std::string> * slotsUsed);
        virtual ~Item();

        Ajout * Clone() const;

    protected:

    private:
        std::vector<std::string> * m_slots;
};

#endif // ITEM_H
