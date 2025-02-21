
#include <filesystem>
#include <string>
#include <vector>
#include "utilities.h"
#include <iostream>
std::array<CSVReader*, 3> leerArchivos(){
    int file_counter = 0;
    std::array<CSVReader*, 3> lectores;
    for(const auto &entrada: std::filesystem::directory_iterator(std::filesystem::current_path())){
        if(entrada.is_regular_file() && entrada.path().extension().string() == ".csv"){
            std::string nombreArchivo{entrada.path().stem().string()};
            if(nombreArchivo == "games"){
                std::cout << entrada.path() << std::endl;
                lectores[0] = new CSVReader(entrada.path().string());
                file_counter++;
            }else if(nombreArchivo == "users"){
                std::cout << entrada.path() << std::endl;
                lectores[1] = new CSVReader(entrada.path().string());
                file_counter++;
            } else if(nombreArchivo == "recommendations"){
                std::cout << entrada.path() << std::endl;
                lectores[2] = new CSVReader(entrada.path().string());
                file_counter++;
            }
        }
    }

    if(file_counter != 3){
        lectores[0] = nullptr;
    }
    return lectores;
}

void formarUsers(CSVReader *lector, std::unordered_map<int, User> &usuarios){
    for(auto &fila: *lector){
        const int id {fila["user_id"].get<int>()};
        usuarios[id] = User(id);
    }
}

void formarGames(CSVReader *lector, std::unordered_map<int, Games> &juegos)
{
    for(auto &fila: *lector){
        const int id {fila["app_id"].get<int>()};
        const std::string titulo{fila["title"].get<std::string>()};
        juegos[id] = (Games(id, titulo));
    }
}

void procesarRecomendaciones(CSVReader *lector, std::unordered_map<int, User> &usuarios, std::unordered_map<int, Games> &juegos)
{
    for(auto &fila: *lector){
        const bool fueRecomendado = fila["is_recommended"].get<bool>();
        if(fueRecomendado){
            const int juego_id {fila["app_id"].get<int>()};
            const int user_id {fila["app_id"].get<int>()};
            const std::string titulo{fila["title"].get<std::string>()};
            Games juego = juegos[juego_id];
            juego.incrementRecommendation();
            usuarios[user_id].incrementRecommendation(juego);
        }
    }
}
