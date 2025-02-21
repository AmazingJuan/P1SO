#include <iostream>
#include <chrono>
#include <map>
#include <vector>
#include "includes/csv.hpp"
#include "utilities.h"
#include "games.h"
#include "user.h"

using namespace csv;
int main(){
    auto start{std::chrono::high_resolution_clock::now()};
    std::array<CSVReader*, 3> lectores{leerArchivos()};

    std::unordered_map<int, User> usuarios;
    std::unordered_map<int, Games> juegos;
    formarUsers(lectores[1], usuarios);
    formarGames(lectores[0], juegos);
    procesarRecomendaciones(lectores[2], usuarios, juegos);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << duration.count() << std::endl;
    std::cout << usuarios.size() << std::endl;
    std::cout << juegos.size() << std::endl;
    int x;
    std::cin >> x; 
}