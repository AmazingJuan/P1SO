#include <iostream>
#include <chrono>
#include <set>
#include <vector>
#include "includes/csv.hpp"
#include "utilities.h"
#include "games.h"
#include "gamerec.h"
#include "user.h"

using namespace csv;
int main(){
    auto start{std::chrono::high_resolution_clock::now()};
    std::array<CSVReader*, 3> lectores{leerArchivos()};

    std::unordered_map<int, User*> usuariosAux;
    std::unordered_map<int, Games*> juegosAux;
    formarUsers(lectores[1], usuariosAux);
    formarGames(lectores[0], juegosAux);
    std::cout << "estoy aca";
    procesarRecomendaciones(lectores[2], usuariosAux, juegosAux);
    std::set<User> usuarios;
    std::set<Games> juegos;
    std::cout << "estoy aka" << std::endl;
    ordenarJuegos(juegos, juegosAux);
    ordenarUsuarios(usuarios, usuariosAux);
    int counter = 0;
    /*
    for(auto it = usuarios.rbegin(); counter < 10; ++it){
        std::cout << it->user_id << " con " << it->recommendations << std::endl;
        ++counter;
        std::cout << std::endl << std::endl;
    }
    */

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << duration.count() << std::endl;
}