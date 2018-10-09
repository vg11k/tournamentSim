#include "Option.hpp"

Option::Option()
{
    //ctor
}

Option::~Option()
{
    //dtor
}

Ajout * Option::Clone() const {
    return (new Option(*this));
}
