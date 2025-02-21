#include "user.h"
User::User(){

}

User::User(int user_id){
    this->user_id = user_id;
}

void User::incrementRecommendation(Games &juego)
{
    recommended_games.push_back(juego);
    recommendations++;
}
