#pragma once
#include "Card.h"
#include <cassert> //assert()
#include <array>

class Deck{
    public:
    Deck();

    void shuffleDeck();

    void printDeck() const;

    const Card& dealCard();

    private:
    size_t m_cardIndex = 0;
    static const size_t m_size = 52;
    std::array<Card, m_size> m_deck;

    static void swapCard(Card& card1, Card& card2);

    static int getRandomNumber(int min, int max);
};