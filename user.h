#ifndef USER_H
#define USER_H
#include <vector>
#include "games.h"
class User{
    private:
        int user_id;
        int recommendations;
        std::vector<Games> recommended_games;
        
    public:
        User();
        User(const int user_id);
        void incrementRecommendation(Games &juego);
};

#endif