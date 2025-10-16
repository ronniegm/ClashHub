#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std

Usuario::Usuario(string email, string password, string gamertag)
    : email(email), password(password), gamertag(gamertag), ELO(0.0) {}


bool Usuario::authenticate_Login_Credentials(string inputEmail, string inputPassword) {
    return (email == inputEmail && password == inputPassword);
}


bool Usuario::update_User_Gamertag(string new_gamertag) {
    if (!new_gamertag.empty()) {
        gamertag = new_gamertag;
        return true;
    }
    return false;
}


bool Usuario::update_User_ELO(double new_ELO) {
    if (new_ELO >= 0) {
        ELO = new_ELO;
        return true;
    }
    return false;
}

bool Usuario::add_User_Teams_Reference(Referencia_de_Equipo* nuevoEquipo) {
    if (nuevoEquipo != nullptr) {
        teams.push_back(nuevoEquipo);
        return true;
    }
    return false;
}


string Usuario::getGamertag() const { return gamertag; }
string Usuario::getEmail() const { return email; }
double Usuario::getELO() const { return ELO; }
vector<Referencia_de_Equipo*> Usuario::getTeams() const { return teams; }


void Usuario::setPassword(string newPassword) { password = newPassword; }
