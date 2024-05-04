#pragma once
#include <iostream>

class Card{
    public:

    enum CardSuit{
        SUIT_TREFU,
        SUIT_BYBNU,
        SUIT_PIKI,
        SUIT_CHERVU,
        MAX_SUITS
    };

    enum CardRank{
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_VALET,
        RANK_DAMA,
        RANK_KING,
        RANK_TYZ,
        MAX_RANKS
    };

    Card(CardRank rank=MAX_RANKS, CardSuit suit=MAX_SUITS);

    void printCard() const;

    size_t getValueCard() const;

    private:
    CardSuit m_suit;
    CardRank m_rank;
};