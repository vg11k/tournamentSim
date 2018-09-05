#include <iostream>

#include "debug.hpp"
#include "ProfileManager.hpp"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    //testJSONParserLib();
    //testPersonnageGenerator();
    ProfileManager *  manager = ProfileManager::getMe();

    cout << "Bye world!" << endl;

    return 0;
}
