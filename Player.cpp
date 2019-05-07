/*Adi Achwal 311233688*/
#include "Player.h"
using namespace std;

bool Player ::play(Card& curr_card) {
    int move;
    cout << getName() <<", your turn - "<< endl;
    cout << "Your cards: ";
    for (size_t i = 0; i < cards.size(); i++) {
        cout << "("<<i+1<<")"<<cards.at(i);
    }
    cout << endl;
    cin >> move;

    while((move > 0) && (move <= (int)cards.size()) && !curr_card.is_legal(cards.at(move-1))){
        cout << "You can't put "<<cards.at(move-1)<<" on "<<curr_card << endl;
        cin >> move; //waiting for another input
    }
    if(move > (int)cards.size()||move <= 0){
        Card temp = Card::generate_card();
        cards.push_back(temp);
        return 0;
    }
    else{
        curr_card = cards.at(move-1);
        cards.erase(cards.begin()+(move-1));
    }
    return 1;
};
bool Player::_isWinner(){
    if(cards.size() == 0){
        return true;
    }
    return false;
}