#include "Juegos_BD.h"
#include <vector>
std::vector<Juego> Juegos_DB::coleccion;

void Juegos_DB::init() {
    coleccion = File_Manager::read_File<Juego>("juego");
}

bool Juegos_DB::create_Juego(Juego* juego) {
    coleccion.push_back(*juego);
    return true;
}

Juego* Juegos_DB::read_Juego(int id) {
    for (auto& j : coleccion) {
        if (j.getId() == id) {
            return new Juego(j);
        }
    }
    return nullptr;
}

bool Juegos_DB::update_Juego(Juego* juego) {
    for (auto& j : coleccion) {
        if (j.getId() == juego->getId()) {
            j = *juego;
            return true;
        }
    }
    return false;
}

bool Juegos_DB::delete_Juego(int id) {
    for (size_t i = 0; i < coleccion.size(); i++) {
        if (coleccion[i].getId() == id) {
            coleccion.erase(coleccion.begin() + i);
            return true;
        }
    }
    return false;
}

bool Juegos_DB::save() {
    return File_Manager::write_File<Juego>("juego", coleccion);
}
