#include "user.h"
#include <algorithm>
#include <iostream>
User::User(){
}

User::User(int user_id){
    this->user_id = user_id;
    recommendations = 0;
}

void User::sortGames()
{
    std::sort(recommended_games.begin(), recommended_games.end(), std::greater<GameRec>());
}

void User::incrementRecommendation(Games *juego, const int juego_id)
{
    auto it1 = recommended_games.end();
    auto it2 = std::find(recommended_games.begin(), it1, juego);

    if(it1 == it2){
        recommended_games.push_back(GameRec(juego));
    }
    else{
        std::cout << "estoy akiki";
        recommended_games[std::distance(recommended_games.begin(), it2)].addRecommendation();
    }
    recommendations++;
}

bool User::operator<(const User &usuarior) const
{
    return recommendations < usuarior.recommendations;
}
