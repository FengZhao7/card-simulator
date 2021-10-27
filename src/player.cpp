#include "../include/function.h"

Player *initialOwner()
{
    Player *owner=new Player();

    
    vector<Killer*> killerOwner (3); // each player has 3 killer
    
    //initKiller(class, killer id, host id, killer hp, killer speed, killer moral, killer skill, killer card, killer loacation)
    // class: 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'
    // killer id: 1, 2, 3.... 
    // host id: 1-owner, 2-opponent
    // killer hp: max-61
    // killer speed: max-61
    // killer moral: max-61
    // killer skill: max-61
    // max(hp+speed+moral+skill) is 164
    // killer card: [card1 id, card2 id, card3 id, card4 id]
    // killer location: 1, 2, 3, 4, 5, 6, 7
    //     o 1
    // o 2     o 3
    //     o 4
    // o 5     o 6
    //     o 7

    int cardId1[4]={3,4,5,6}; // each killer has 4 cards 
    killerOwner[0] = initKiller('B', 1, 1, 50, 33, 15, 40,cardId1,5);

    int cardId2[4]={7,8,9,10};
    killerOwner[1] = initKiller('B', 2, 1, 40, 14, 20, 37,cardId2,2);

    int cardId3[4]={11,12,13,14};
    killerOwner[2] = initKiller('B', 3, 1, 35, 29, 50, 44,cardId3,3);
   

   vector<Card*> ownerCards= initCardStack(killerOwner); // initialize 24 cards owned by the player 
   owner->killers=killerOwner;
   owner->cards=ownerCards;

   return owner;


}

Player *initialOpponent()
{
    Player *opp=new Player();

    
    vector<Killer*> killerOpp (3); // each player has 3 killer
    
    //initKiller(class, killer id, host id, killer hp, killer speed, killer moral, killer skill, killer card, killer loacation)
    // class: 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'
    // killer id: 1, 2, 3.... 
    // host id: 1-owner, 2-opponent
    // killer hp: max-61
    // killer speed: max-61
    // killer moral: max-61
    // killer skill: max-61
    // max(hp+speed+moral+skill) is 164
    // killer card: [card1 id, card2 id, card3 id, card4 id]
    // killer location: 1, 2, 3, 4, 5, 6, 7
    //     o 1
    // o 2     o 3
    //     o 4
    // o 5     o 6
    //     o 7

    int cardId1[4]={15,16,17,18}; // each killer has 4 cards 
    killerOpp[0] = initKiller('A', 1, 2, 46, 7, 61, 22,cardId1,3);

    int cardId2[4]={19,20,21,22};
    killerOpp[1] = initKiller('C', 2, 2, 57, 14, 23, 38,cardId2,6);

    int cardId3[4]={23,24,25,26};
    killerOpp[2] = initKiller('D', 3, 2, 55, 27, 56, 42,cardId3,5);
   

   vector<Card*> oppCards= initCardStack(killerOpp); // initialize 24 cards owned by the player 
   opp->killers=killerOpp;
   opp->cards=oppCards;

   return opp;


}