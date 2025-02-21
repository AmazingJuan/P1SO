#include "games.h"

Games::Games(){

}
Games::Games(const unsigned int app_id, const std::string titulo){
    this -> app_id = app_id;
    this -> titulo = titulo;
    
}

void Games::incrementRecommendation()
{
    recommendations++;

}
