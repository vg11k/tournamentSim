#ifndef DEBUG_HPP_INCLUDED
#define DEBUG_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <fstream>

#include <nlohmann/json.hpp>
#include "Constants.h"
#include "Personnage.hpp"
#include "CSVParser.hpp"
#include "Tournament.hpp"

void testJSONParserLib();
void testPersonnageGenerator();
void testCSVParser();
void testFight();


#endif // DEBUG_HPP_INCLUDED
