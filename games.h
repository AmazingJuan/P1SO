#ifndef GAMES_H
#define GAMES_H
#include <string>
class Games{
    private:
        unsigned int app_id;
        std::string titulo;
        unsigned int recommendations;
    public:
        Games();
        Games(const unsigned int app_id, const std::string titulo);
        void incrementRecommendation();
};
#endif