/*Adi Achwal 311233688*/

#include "Game.h"
#include <iostream>
using namespace std;


inline void check(int n){// check that the players or cards are positive
    if(n <= 0){
        //throw invalid_argument("illeggal numbers of players or cards! must be bigger than 0");
        throw 20;
    }
}

void Game ::init_game() {
    //int play;
    int cards;

    cout<<"How many players?"<<endl;
    cin>>num_of_players;
    check(num_of_players);

    cout<<"How many cards?"<<endl;
    cin>>cards;
    check(cards);

    index = 0; // first player
    dir = 0; //going forward
    string p_name;
    for (int i = 0; i < num_of_players ; ++i) {
        cout<<"player number " <<i+1<<" name?"<<endl;
        cin>>p_name;
        Player p(p_name,cards);
        players.push_back(p);
    }
    curr_card = Card::generate_card();
    curr_player = &players.at(index);
}

bool Game::turn(){
    return curr_player->play(curr_card);
}

void Game:: sNext(){
    if(dir == 0){
        index = (index+1)%num_of_players;
    }
    if(dir == 1){
        index = (index-1+num_of_players)%num_of_players;
    }
    curr_player=&players.at(index);
}
void Game::next(){  //check who is next method
    if(curr_card.get_sign()!= sign::PLUS){
        if(curr_card.get_sign() == sign::CD){
            dir=!dir;  //direction backwards
        }

        if(dir == 0){
            if(curr_card.get_sign() == sign::STOP){
                index=(index+2)%num_of_players;
            }
            else{index=(index+1)%num_of_players;}
        }

        if(dir==1){
            if(curr_card.get_sign() == sign::STOP){
                index=(index-2+num_of_players)%num_of_players;
            }
            else{index=(index-1+num_of_players)%num_of_players;}
        }
    }
    curr_player=&players.at(index);

}

void Game::winPrint(){
    cout << winner->getName()<<" wins!" << '\n';
}


void Game::start(){
    winner=NULL; //no one is winner at that point
    try{
        init_game(); //method to start the game and restart fields
    }
    catch(int e){return;}
    while(!winner){
        cout << "current: " <<curr_card<<endl;
        if(turn()){
            if(curr_player->_isWinner()){
                winner=curr_player;
            }
            next();
        }
        else{
            if(curr_player->_isWinner()){
                winner=curr_player;
            }
            sNext();
        }
    }
    winPrint();
};

