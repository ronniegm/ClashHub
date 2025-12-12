#ifndef ADMINISTRADORES_BD_H
#define ADMINISTRADORES_BD_H
#include <vector>
#include "Administrador.h"
#include "File_Manager.h"

class Administradores_DB {
private:
    static std::vector<Administrador> coleccion;

public:
    static void init();
    static bool create_Administrador(Administrador* admin);
    static Administrador* read_Administrador(int id);
    static bool update_Administrador(Administrador* admin);
    static bool delete_Administrador(int id);

    static bool save();
};

#endif // ADMINISTRADORES_BD_H
