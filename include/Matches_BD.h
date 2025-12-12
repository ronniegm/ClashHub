#ifndef MATCHES_BD_H
#define MATCHES_BD_H
#include <vector>
#include "Match.h"
#include "File_Manager.h"

class Matches_DB {
private:
    static std::vector<Match> coleccion;

public:
    static void init();
    static bool create_Match(Match* match);
    static Match* read_Match(int id);
    static bool update_Match(Match* match);
    static bool delete_Match(int id);

    static bool save();
};

#endif // MATCHES_BD_H
