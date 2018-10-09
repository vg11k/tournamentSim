#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#include <sstream>
#include <fstream>

#include "NakedProfile.hpp"
#include "FactoryAjout.hpp"

class ProfileManager
{
    public:
        static ProfileManager * getMe();
        virtual ~ProfileManager();

        NakedProfile * getProfile(std::string type);
        Ajout * getAjout(const std::string& name);
        typedef std::map<std::string, NakedProfile*>  ProfileMap;

    protected:

    private:
        static ProfileManager * m_me;
        std::map<std::string, NakedProfile*> * m_profils;
        FactoryAjout * m_factory;
        void loadFaction(std::string factionFolderName);

        ProfileManager();
};

#endif // PROFILEMANAGER_H
