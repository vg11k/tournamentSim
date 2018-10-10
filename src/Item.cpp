#include "Item.hpp"

using namespace std;

Item::Item(string name, vector<string> * slotUsed) : Ajout(name) {
    m_slots = slotUsed;
}

Item::~Item()
{
    //dtor
}

Ajout * Item::Clone() const {
    return (new Item(*this));
}
