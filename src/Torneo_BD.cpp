#include "Torneo_BD.h"
#include <vector>
std::vector<Torneo> Torneos_DB::coleccion;

void Torneos_DB::init() {
    coleccion = File_Manager::read_File<Torneo>("torneo");
}

bool Torneos_DB::create_Torneo(Torneo* torneo) {
    coleccion.push_back(*torneo);
    return true;
}

Torneo* Torneos_DB::read_Torneo(int id) {
    for (auto& t : coleccion) {
        if (t.getId() == id) {
            return new Torneo(t);
        }
    }
    return nullptr;
}

bool Torneos_DB::update_Torneo(Torneo* torneo) {
    for (auto& t : coleccion) {
        if (t.getId() == torneo->getId()) {
            t = *torneo;
            return true;
        }
    }
    return false;
}

bool Torneos_DB::delete_Torneo(int id) {
    for (size_t i = 0; i < coleccion.size(); i++) {
        if (coleccion[i].getId() == id) {
            coleccion.erase(coleccion.begin() + i);
            return true;
        }
    }
    return false;
}

bool Torneos_DB::save() {
    return File_Manager::write_File<Torneo>("torneo", coleccion);
}
