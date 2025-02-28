#ifndef USER_H
#define USER_H
#include <vector>
#include "games.h"
#include "gamerec.h"
class User{
    private:   
        std::vector<GameRec> recommended_games;
        int user_id;
        int recommendations;
    public:
        User();
        User(const int user_id);
        void sortGames();
        void incrementRecommendation(Games *juego, const int juego_id);
        bool searchGame(const int juego_id, int &index);
        bool operator<(const User &usuarior) const;
};

#endif