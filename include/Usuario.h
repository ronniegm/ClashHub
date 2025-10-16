#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <locale>
#include <codecvt>

#ifdef _WIN32
#include <windows.h>
#endif


#include "Referencia_de_Equipo.h"
using namespace std;

class Usuario
{
public:

    Usuario();
    Usuario(string gamertag, string email, string password);

 
    bool authenticate_Login_Crendentials(string user_Password);
    void update_User_Gamertag(string new_Gamertag);
    void update_User_ELO(int new_ELO);
    void add_User_Team_Reference(Referencia_de_Equipo* equipo);
    string get_Email();

   
    void show_User_Info() const;

    
    string serialize() const;
    static Usuario deserialize(const string& line);

   
    map<string, string> toMap() const {
        map<string, string> m;
        m["gamertag"] = gamertag;
        m["email"] = email;
        m["password"] = password;
        m["ELO"] = to_string(ELO);
        return m;
    }

private:
    string gamertag;
    string email;
    string password;
    int ELO;
    vector<Referencia_de_Equipo*> teams;
};

#endif // USUARIO_H
