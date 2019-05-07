/*Adi Achwal 311233688*/

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Card.h"
using namespace std;

class Player {
private:
    string name;
    int num_of_cards;
    //vector of cards
    //private members
    vector<Card> cards;
    Player(){};
    

public:
    //public members
    ~Player(){}
    Player(string name, int num_of_cards):name(name),num_of_cards(num_of_cards) {
        for (int i = 0; i < num_of_cards; ++i) {
            this->cards.push_back(Card::generate_card());
        }
    }

    Player(const Player &other) { //copy c'tor
        this->name = other.name;
        this->num_of_cards = other.num_of_cards;
        for (int i = 0; i < num_of_cards; ++i) {
            this->cards.push_back(other.cards.at(i));
        }
    }

    Player operator=(const Player& player ){
        this->name=player.name;
        this->num_of_cards=player.num_of_cards;
        for (int i = 0; i < num_of_cards; i++) {
            this->cards.push_back(player.cards.at(i));
        }
        return *this;
    }


    string getName(){return this->name;}
    bool play(Card&);
    bool _isWinner();
};
#endif



