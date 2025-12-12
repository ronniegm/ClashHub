#ifndef USUARIO_BD_H
#define USUARIO_BD_H

#include <vector>
#include <string>
#include "Usuario.h"
#include "File_Manager.h"

class Usuarios_DB {
private:
    static std::vector<Usuario> coleccion;

public:
    static void init();
    static bool create_Usuario(Usuario* usuario);
    static Usuario* read_Usuario(int id);
    static bool update_Usuario(Usuario* usuario);
    static bool delete_Usuario(int id);

    l
    static bool authenticate(const std::string& email, const std::string& password);

    static bool save();
};

#endif // USUARIO_BD_H
