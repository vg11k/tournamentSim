#include "ProfileManager.hpp"

using namespace std;
using Json = nlohmann::json;

ProfileManager * ProfileManager::m_me = NULL;

ProfileManager::ProfileManager()
{
    m_profils = new map<string, NakedProfile*>();
    m_factory = new FactoryAjout();

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
    delete m_factory;
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

    cout << "Chargement de la faction " << faction << " : " << endl;

    map<string, NakedProfile*> noPtrMap = *m_profils;

    int nbPersonnages = jsonObject[Constants::STRING_NAME_PROFILS].size();
    for(int i = 0; i < nbPersonnages; i++) {
        Json jProfiles  = jsonObject[Constants::STRING_NAME_PROFILS][i];
        NakedProfile nakedProfile = jProfiles;

        //oblige de passer par une reference intermediaire : la construction json ne prends pas les pointeurs
        //et ne supporte pas les constructeurs multiples
        NakedProfile * profilePtr = new NakedProfile();
        profilePtr->retrieveFrom(nakedProfile);
        profilePtr->setFaction(faction);

        //noPtrMap[profilePtr->getType()] = profilePtr;
        (*m_profils)[profilePtr->getType()] = profilePtr;

        cout << profilePtr->getType() << " charge " << endl;
    }
}

NakedProfile * ProfileManager::getProfile(std::string type) {

    ProfileMap::iterator  it=  m_profils->find(type);
    if( it == m_profils->end() ) {
         throw std::invalid_argument( string("unknown character type asked : [") + type + string("]"));
    }
    return it->second;
}

Ajout * ProfileManager::getAjout(const std::string& name) {
    Ajout * ajout = m_factory->Create(name);
}
