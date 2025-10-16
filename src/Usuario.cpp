#include "Usuario.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// * Class Required
#include "Referencia_de_Equipo.h"


Usuario::Usuario() {
    this->gamertag = "Undefined";
    this->email = "Undefined";
    this->password = "Undefined";
    this->ELO = 0;
    this->teams = {};
}

Usuario::Usuario(string gamertag, string email, string password) {
    this->gamertag = gamertag;
    this->email = email;
    this->password = password;
    this->ELO = 0;
    this->teams = {};
}


bool Usuario::authenticate_Login_Crendentials(string user_Password) {
    if (this->password == user_Password) {
        cout << " Autenticación exitosa. Bienvenido " << gamertag << "!\n";
        return true;
    } else {
        cout << " Contraseña incorrecta para el usuario: " << gamertag << endl;
        return false;
    }
}

void Usuario::update_User_Gamertag(string new_Gamertag) {
    cout << "Gamertag actualizado de '" << gamertag << "' a '" << new_Gamertag << "'\n";
    this->gamertag = new_Gamertag;
}

void Usuario::update_User_ELO(int new_ELO) {
    cout << " ELO actualizado de " << ELO << " a " << new_ELO << endl;
    this->ELO = new_ELO;
}

void Usuario::add_User_Team_Reference(Referencia_de_Equipo* equipo) {
    teams.push_back(equipo);
    cout << " Equipo agregado: " << equipo->nombre << endl;
}

string Usuario::get_Email() {
    return this->email;
}



string Usuario::serialize() const {
    stringstream ss;
    ss << gamertag << "|" << email << "|" << password << "|" << ELO << "|";

    for (size_t i = 0; i < teams.size(); ++i) {
        ss << teams[i]->id;
        if (i != teams.size() - 1) ss << ",";
    }

    return ss.str();
}

Usuario Usuario::deserialize(const string& line) {
    stringstream ss(line);
    string token;
    vector<string> parts;

   
    while (getline(ss, token, '|')) {
        parts.push_back(token);
    }

    Usuario user(
        parts.size() > 0 ? parts[0] : "",
        parts.size() > 1 ? parts[1] : "",
        parts.size() > 2 ? parts[2] : ""
    );

    if (parts.size() > 3) {
        user.ELO = stoi(parts[3]);
    }

    // Deserializar equipos si existen
    if (parts.size() > 4) {
        stringstream teamSS(parts[4]);
        string teamId;
        while (getline(teamSS, teamId, ',')) {
            Referencia_de_Equipo* teamRef = new Referencia_de_Equipo(teamId);
            user.teams.push_back(teamRef);
        }
    }

    return user;
}



void Usuario::show_User_Info() const {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
    setlocale(LC_ALL, "");

    cout << "\n Información del Usuario\n";
    
    cout << " Gamertag: " << gamertag << endl;
    cout << " Email: " << email << endl;
    cout << " Contraseña: " << password << endl;
    cout << " ELO: " << ELO << endl;
    cout << " Equipos asociados: ";

    if (teams.empty()) {
        cout << "Ninguno";
    } else {
        for (size_t i = 0; i < teams.size(); ++i) {
            cout << teams[i]->id;
            if (i != teams.size() - 1) cout << ", ";
        }
    }

    
}
