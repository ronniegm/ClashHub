#ifndef JUEGOS_BD_H
#define JUEGOS_BD_H
#include <vector>
#include "Juego.h"
#include "File_Manager.h"

class Juegos_DB {
private:
    static std::vector<Juego> coleccion;

public:
    static void init();
    static bool create_Juego(Juego* juego);
    static Juego* read_Juego(int id);
    static bool update_Juego(Juego* juego);
    static bool delete_Juego(int id);

    static bool save();
};


#endif // JUEGOS_BD_H
