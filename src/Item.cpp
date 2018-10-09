#include "Item.hpp"

Item::Item()
{

}

Item::~Item()
{
    //dtor
}

Ajout * Item::Clone() const {
    return (new Item(*this));
}
