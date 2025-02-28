#ifndef GAMES_H
#define GAMES_H
#include <string>
class Games{
    private:
        unsigned int recommendations;
        std::string titulo;
        int app_id;
    public:
        Games();
        Games(const unsigned int app_id, const std::string titulo);
        void incrementRecommendation();

        bool operator<(const Games &otro) const;
};
#endif