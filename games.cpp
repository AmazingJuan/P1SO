#include "games.h"

Games::Games(){

}
Games::Games(const unsigned int app_id, const std::string titulo){
    this -> app_id = app_id;
    this -> titulo = titulo;
    recommendations = 0;
}

void Games::incrementRecommendation()
{
    recommendations++;

}

bool Games::operator<(const Games &otro) const
{
    return recommendations < otro.recommendations;
}
