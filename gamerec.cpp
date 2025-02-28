#include "GameRec.h"

GameRec::GameRec(){
}

GameRec::GameRec(Games *juego)
{
    this -> juego = juego;
    vecesRecomendado = 1;
}

void GameRec::addRecommendation()
{
    vecesRecomendado++;
}


const bool GameRec::operator>(const GameRec & game) const
{
    return vecesRecomendado > game.vecesRecomendado;
}

const bool GameRec::operator==(const Games *game) const
{
    return juego == game;
}
