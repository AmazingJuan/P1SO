#ifndef GAMEREC_H
#define GAMEREC_H
#include "games.h"
class GameRec{
    private:
        Games *juego;
        int vecesRecomendado;
    public:
        GameRec();
        GameRec(Games *juego);
        void addRecommendation();
        const bool operator>(const GameRec &game) const;
        const bool operator==(const Games *game) const;
};


#endif
