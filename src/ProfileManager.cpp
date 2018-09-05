#include "ProfileManager.hpp"

using namespace std;
using Json = nlohmann::json;

ProfileManager * ProfileManager::m_me = NULL;

ProfileManager::ProfileManager()
{
    m_profils = new map<string, NakedProfile>();

    DIR *dp;
    struct dirent *ep;

    dp = opendir ("./factions");
    if (dp != NULL)
    {
        while (ep = readdir (dp)) {
            if(string(ep->d_name).compare(".") != 0 && string(ep->d_name).compare("..") != 0) {
                loadFaction(ep->d_name);
            }
        }
        (void) closedir (dp);
    }
    else
        perror ("Couldn't open the directory");
}

ProfileManager::~ProfileManager()
{
    delete m_profils;
    delete m_me;
    m_me = NULL;
}


ProfileManager * ProfileManager::getMe()
{
    if(m_me == NULL)
    {
        m_me = new ProfileManager();
    }
    return m_me;
}



void ProfileManager::loadFaction(string factionFolderName) {

    string pathname = string("./factions/") + factionFolderName;
    cout << pathname << endl;
    ifstream inputFile(pathname.c_str());
    Json jsonObject;
    inputFile >> jsonObject;
    inputFile.close();

    string faction = jsonObject[Constants::STRING_NAME_FACTION];

    cout << "Chargement de la faction " << faction << " : ";

    int nbPersonnages = jsonObject[Constants::STRING_NAME_PROFILS].size();
    for(int i = 0; i < nbPersonnages; i++) {
        Json jProfiles  = jsonObject[Constants::STRING_NAME_PROFILS][i];
        NakedProfile p = jProfiles;
        cout << p.getType() << " + ";
        m_profils->insert(std::pair<string,NakedProfile>(p.getType(), p));
    }
    cout << endl;
}
