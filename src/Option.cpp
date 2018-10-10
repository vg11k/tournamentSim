#include "Option.hpp"

using namespace std;

Option::Option(string name) : Ajout(name)
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
