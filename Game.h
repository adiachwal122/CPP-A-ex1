/*Adi Achwal 311233688*/

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
using namespace std;


class Game {
private:
    //private members and functions
    Player* curr_player;
    Player* winner;
    Card curr_card;
    int index;
    int num_of_players;
    vector <Player> players;

    void init_game();
    bool turn();
    void sNext();
    void next();
    bool dir;
    void winPrint();


    Game(const Game& game){};
    Game operator=(const Game& game){return *this;} //to prevent default copy

public:
    //public members and functions
    Game(){}
    ~Game(){}
    void start();
    Card& getCurrentCard(){return curr_card;}
};
#endif




