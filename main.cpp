#include <iostream>
#include <time.h>

#include "debug.hpp"
#include "ProfileManager.hpp"
#include "Tournament.hpp"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    srand(time(NULL)); // initialisation de rand

    //testJSONParserLib();
    //testPersonnageGenerator();

    //testCSVParser();

    testFight();

    cout << "Bye world!" << endl;

    return 0;
}
