#ifndef KILLER_H
#define KILLER_H 

#include "buff.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace ::std;


enum killerStatus{DEAD, ALIVE, LASTTURN};


class Card
{   public:
    char cls;
    unsigned int id;
    unsigned int id_host;
    unsigned int part;
    Debuff *debuff;
    Buff *buff;
    unsigned int dmg;
    unsigned int shield;
    unsigned int energy;
    unsigned int range;
    void Show()
    {

        cout<<"id: " <<id <<" , host id :" <<id_host <<", part: " << part << ", shield: " <<shield \
        <<", damage:" << dmg <<", energy:" <<energy <<endl;
        if(buff)
            buff->Show();
        if(debuff)
            debuff->Show();

    }

};

class Property
{
    public:
    int hp;
    unsigned int moral;
    unsigned int skill;
    unsigned int speed;
	float attack;
    void Show()
    {
        cout<<"hp " << hp <<" moral: " <<moral <<" skill: " <<skill << " speed: " <<speed <<" attack: " <<attack <<endl;
    }
};


class  Killer
{   
    public:
    char cls;
    unsigned int id;
    unsigned int id_host;
    int shield;
    Property original;
    Property current;
    killerStatus status;
    vector<Card*> cards;
    vector<Card*> cardsToUse;
    vector<Card*> cardsCanUse;
    vector <Buff> buff; 
    vector <Debuff> debuff;
    unsigned int location;
    unsigned int pirority;
    int ticks;

    void Show()
    {
        cout<<"打手 id: " << id <<" "<< "玩家 id:" << id_host <<" " <<"shield :" << shield <<" "<< " class : " <<cls <<endl;
        cout<< "current status " <<status << endl;
        cout<<"orginal property:"<<endl;
        original.Show();
        cout<< "current property"<<endl;
        current.Show();
        for(int i=0; i<cards.size(); i++)
        {
            cards[i]->Show();
        }
        cout<< "buffs" << endl;
        for (int i=0; i<buff.size(); i++){
            buff[i].Show();
        }
        cout<< "debuffs" <<endl;
        for(int i=0; i<debuff.size(); i++)
        {
            debuff[i].Show();
        }
        
    }

};


class Player
{
    public:
    vector<Killer*> killers;
    unsigned int energy;
    vector<Card*> cards;
    vector<Card*> cardsReject;

    Player()
    {
        energy=3;
    }



};

class Game
{
    public:
    Player *player1;
    Player *opponent;
    
    unsigned int turn;
    Game ()
    {
        turn=0;
    }
};







#endif

