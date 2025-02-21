#include "includes/csv.hpp"
#include <array>
#include <vector>
#include <unordered_map>
#include "user.h"
#include "games.h"
using namespace csv;
std::array<CSVReader*, 3> leerArchivos();
void formarUsers(CSVReader *lector, std::unordered_map<int, User> &usuarios);
void formarGames(CSVReader *lector, std::unordered_map<int, Games> &juegos);
void procesarRecomendaciones(CSVReader *lector, std::unordered_map<int, User> &usuarios, std::unordered_map<int, Games> &juegos);

