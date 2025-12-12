#ifndef TORNEO_BD_H
#define TORNEO_BD_H
#include <vector>
#include "Torneo.h"
#include "File_Manager.h"

class Torneos_DB {
private:
    static std::vector<Torneo> coleccion;

public:
    static void init();
    static bool create_Torneo(Torneo* torneo);
    static Torneo* read_Torneo(int id);
    static bool update_Torneo(Torneo* torneo);
    static bool delete_Torneo(int id);

    static bool save();
};

#endif // TORNEO_BD_H
