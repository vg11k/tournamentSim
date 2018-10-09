#include "Item.hpp"

Item::Item()
{
    //ctor
}

Item::~Item()
{
    //dtor
}

Ajout * Item::Clone() const {
    return (new Item(*this));
}
