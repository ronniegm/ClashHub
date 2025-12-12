#include "Administradores_BD.h"
#include <vector>
std::vector<Administrador> Administradores_DB::coleccion;

void Administradores_DB::init() {
    coleccion = File_Manager::read_File<Administrador>("administrador");
}

bool Administradores_DB::create_Administrador(Administrador* admin) {
    coleccion.push_back(*admin);
    return true;
}

Administrador* Administradores_DB::read_Administrador(int id) {
    for (auto& a : coleccion) {
        if (a.getId() == id) {
            return new Administrador(a);
        }
    }
    return nullptr;
}

bool Administradores_DB::update_Administrador(Administrador* admin) {
    for (auto& a : coleccion) {
        if (a.getId() == admin->getId()) {
            a = *admin;
            return true;
        }
    }
    return false;
}

bool Administradores_DB::delete_Administrador(int id) {
    for (size_t i = 0; i < coleccion.size(); i++) {
        if (coleccion[i].getId() == id) {
            coleccion.erase(coleccion.begin() + i);
            return true;
        }
    }
    return false;
}

bool Administradores_DB::save() {
    return File_Manager::write_File<Administrador>("administrador", coleccion);
}
