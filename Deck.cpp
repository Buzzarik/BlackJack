#include "Deck.h"

Deck::Deck(){
    size_t card = 0;
    for (size_t suit = 0; suit < Card::MAX_SUITS; ++suit){
        for (size_t rank = 0; rank < Card::MAX_RANKS; ++rank){
            m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
            ++card;
        }
    }
}

void Deck::shuffleDeck(){
    for (size_t i = 0; i < m_size; i++){
        swapCard(m_deck[i], m_deck[getRandomNumber(0, m_size - 1)]);
    }
    m_cardIndex = 0;
}

void Deck::printDeck() const{
    for (const auto& card : m_deck){
        card.printCard();
        std::cout << std::endl;
    }
}

const Card& Deck::dealCard(){
    assert(m_cardIndex < m_size);
    return m_deck[m_cardIndex++];
}

void Deck::swapCard(Card& card1, Card& card2){
    std::swap(card1, card2);
}

int Deck::getRandomNumber(int min, int max){
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}