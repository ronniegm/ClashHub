#include "Usuario_BD.h"
#include <string>
#include <vector>
std::vector<Usuario> Usuarios_DB::coleccion;

void Usuarios_DB::init() {
    coleccion = File_Manager::read_File<Usuario>("usuario");
}

bool Usuarios_DB::create_Usuario(Usuario* usuario) {
    coleccion.push_back(*usuario);
    return true;
}

Usuario* Usuarios_DB::read_Usuario(int id) {
    for (auto& u : coleccion) {
        if (u.getId() == id) {
            return new Usuario(u);
        }
    }
    return nullptr;
}

bool Usuarios_DB::update_Usuario(Usuario* usuario) {
    for (auto& u : coleccion) {
        if (u.getId() == usuario->getId()) {
            u = *usuario;
            return true;
        }
    }
    return false;
}

bool Usuarios_DB::delete_Usuario(int id) {
    for (size_t i = 0; i < coleccion.size(); i++) {
        if (coleccion[i].getId() == id) {
            coleccion.erase(coleccion.begin() + i);
            return true;
        }
    }
    return false;
}

bool Usuarios_DB::authenticate(const std::string& email, const std::string& password) {
    for (auto& u : coleccion) {
        if (u.getCorreo() == email && u.getPassword() == password) {
            return true;
        }
    }
    return false;
}

bool Usuarios_DB::save() {
    return File_Manager::write_File<Usuario>("usuario", coleccion);
}
