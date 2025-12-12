#include "Matches_BD.h"
#include <vector>
std::vector<Match> Matches_DB::coleccion;

void Matches_DB::init() {
    coleccion = File_Manager::read_File<Match>("match");
}

bool Matches_DB::create_Match(Match* match) {
    coleccion.push_back(*match);
    return true;
}

Match* Matches_DB::read_Match(int id) {
    for (auto& m : coleccion) {
        if (m.getId() == id) {
            return new Match(m);
        }
    }
    return nullptr;
}

bool Matches_DB::update_Match(Match* match) {
    for (auto& m : coleccion) {
        if (m.getId() == match->getId()) {
            m = *match;
            return true;
        }
    }
    return false;
}

bool Matches_DB::delete_Match(int id) {
    for (size_t i = 0; i < coleccion.size(); i++) {
        if (coleccion[i].getId() == id) {
            coleccion.erase(coleccion.begin() + i);
            return true;
        }
    }
    return false;
}

bool Matches_DB::save() {
    return File_Manager::write_File<Match>("match", coleccion);
}
