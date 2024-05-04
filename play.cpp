#include <iostream>
#include <ctime> //time()
#include <cstdlib> //rand(), srand()
#include <string>
#include "Deck.h"


bool playBlackJack(Deck& deck){
    size_t scorePlayer = 0, scoreDiller = 0;
    char choice = 'y';

    while (choice == 'y'){
        scorePlayer += deck.dealCard().getValueCard();
        std::cout << "Your Points = " << scorePlayer << "\n";
        if (scorePlayer > 21)
            return false;
        std::cout << "If you want get card, press 'y'" << std::endl;
        std::cin >> choice;
    }

    while (scoreDiller < 17){
        scoreDiller += deck.dealCard().getValueCard();
    }

    std::cout << "Diller Points = " << scoreDiller << std::endl;
    if (scoreDiller > 21)
        return true;
    else if (scoreDiller > scorePlayer)
        return false;
    else
        return true;
}


int main(){
    srand(static_cast<size_t>(time(0)));
    rand();

    Deck deck;
    deck.shuffleDeck();

    if (playBlackJack(deck))
        std::cout << "You WIN!!!" << std::endl;
    else
        std::cout << "You Lose :(" << std::endl;

    return 0;
}