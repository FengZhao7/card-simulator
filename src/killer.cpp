
#include <iostream>
//#include "f.hpp"
#include "../include/function.h"
#include <random>


Killer *initKiller(char cls, unsigned int id, unsigned int id_host, unsigned int hp, unsigned int speed, unsigned int moral, unsigned int skill, int c[4],int loc)
{
    
    Killer* killer = new Killer();
    killer->cls = cls;
    killer->id=id;
    killer->id_host=id_host;
    killer->original.hp = 156 + hp*6;
    killer->original.moral = moral;
    killer->original.skill = skill;
    killer->original.speed = speed;
	killer->original.attack = 1.0;
    killer->current.hp = 156 + hp * 6;
    killer->current.speed = speed;
    killer->current.moral = moral;
    killer->current.skill = skill;
	killer->current.attack = 1.0;
    killer->status = ALIVE;
    killer->cards=initCardforKiller(c,id);
    killer->location=loc;
    killer->pirority=loc;
    return killer;
}

bool compareSpeed(const Killer* a, const  Killer* b)
{
    if (a->current.speed==b->current.speed)
    {
            if (a->current.hp==b->current.hp)
            {
                if (a->current.skill==b->current.skill)
                {
                    
                    return a->current.moral>b->current.moral;

                }
                else
                   return a->current.skill>b->current.skill;

            }
            else
               return a->current.hp < b->current.hp;
    }
    else
       return a->current.speed > b->current.speed;
}

vector<Killer*> CalculateSpeed (vector<Killer*> &killer_owner, vector<Killer*> &killer_opp)
{

    vector<Killer*> killer(0);
    killer.insert(killer.end(),killer_owner.begin(),killer_owner.end());
    killer.insert(killer.end(),killer_opp.begin(),killer_opp.end());

    sort(killer.begin(),killer.end(),compareSpeed);
    return killer;

}

float classBonus(Killer& from, Killer& to, float ratio)
{
    if(from.cls =='E' || from.cls =='A' || from.cls == 'G')
    {
        if(to.cls == 'B' || to.cls == 'F' || to.cls == 'I')
            return ratio - 0.15;
        else if(to.cls == 'D' || to.cls == 'C' || to.cls == 'H')
            return ratio + 0.15;
        else
            return ratio;
    }
    else if(from.cls =='B' || from.cls =='F' || from.cls == 'I')
    {
        if(to.cls == 'D' || to.cls == 'C' || to.cls == 'H')
            return ratio - 0.15;
        else if(to.cls == 'E' || to.cls == 'A' || to.cls == 'G')
            return ratio + 0.15;
        else
            return ratio;
    }
    else if(from.cls =='D' || from.cls =='C' || from.cls == 'H')
    {
        if(to.cls == 'E' || to.cls == 'A' || to.cls == 'G')
            return ratio - 0.15;
        else if(to.cls == 'B' || to.cls == 'F' || to.cls == 'I')
            return ratio + 0.15;
        else
            return ratio;
    }
    return ratio;
}
float calculateCriticChance(Killer *killer)
{
   for(int i=0; i<killer->debuff.size(); i++)
   {
      if(killer->debuff[i].type == CANTCRITIC){
         return 0;
      }
   }
   if(killer->current.moral <20)
   {
       return 0;
   }
   float chance = (killer->current.moral -20) / 200.0;
   return  chance;
}

int calculateBonusDmg(Killer *killer, Card *card)
{  
   int bonus = card->dmg * killer->current.skill / 500;
   if(killer->cardsToUse.size() >1)
   {
      return bonus;
   }
   return 0;
}

float lastTurnChance(Killer *killer)
{
    for(int i=0; i<killer->debuff.size(); i++)
    {
       if(killer->debuff[i].type ==NOLASTTURN)

       {
          return 0;
       }
    }
    if(killer->current.moral < 10)
    {
        return 0;
    }
   float chance = (killer->current.moral -10) / 100.0;
   return chance;
}
// 
int dealDamage(Killer *from, Killer *to, float ratio, Card *card, float extraDamage, float extraCreticDamage, Player* killerOwner, Player* otherplayer, float creticRate )
{  //cout<<"Go in dealDamage"<<endl;
   //cout<<card->id<<endl;
   //to->Show();
   checkDebuff9(from);
   checkBuffCard7(from,to);
    
   checkBuffCard8 (from, to, otherplayer);
   checkBuffCard13(card, to, otherplayer);
   
   checkBuffCARD38  (to);
  
   checkDebuffCARD65  (to);
   checkBuffCARD133 (from, to);
   // cout<<"In2"<<endl;
   if (checkDebuffCANTCLOSECOMBAINT(card, from))
       return 0;
   if (checkBuffCARD19(card, to))
       return 0;
   if (checkDebuffBool(from, CANTATTACK))
       return 0;
   if (checkBuffBANPART(card, to))
      return 0;
   if (checkBuffCARD20 (card, to, otherplayer))
      return 0;
   if (checkBuffCARD37 (card, from, killerOwner))
      ratio=ratio*1.1;
    if (checkBuffCard106(to))
        ratio = ratio * 0.75;
    if(checkBuffCard125(to))
    {
        if(from->cls =='D' || from->cls == 'C')
        {
            Debuff b;
            b.type = NOSHIELD2;
            from->debuff.push_back(b);
        }
    }
    if(to->status == LASTTURN)
    {
        if (to->ticks <=2)
        {
            to->ticks =0;
            to->status = DEAD;
        }
        else
            to->ticks -=2;
        
        return 0;
    }

  
   ratio = classBonus(*from, *to, ratio);
   ratio = cardBonus(from, card, ratio);
   int damage = int(card->dmg * ratio *(1 + extraDamage));
   int bonusDmg = calculateBonusDmg(from, card);
   float criticChance; 
   if (creticRate==1)
       criticChance=1;
   else
       criticChance = calculateCriticChance(from)*(1+creticRate);
   if (checkBuffCARD73 (to))
       criticChance=0;
   if (checkDebuffBool(from, CANTCRITIC))
       criticChance=0;
   float random = float(rand())/float(RAND_MAX);
   if (random < criticChance)
   {  
      damage = int(damage * (2+extraCreticDamage));
   }

   if (checkDebuffBoolNext(to, GETDOUBLEDAMAGE))
      damage=2*damage;
   bool useShield=checkDebuffBoolNext(to, NOSHIELD1);
   if (to->shield > damage && useShield)
   {
      to->shield -= damage;
      if (to->shield>0 && checkDebuffBoolNext(to, SHIELDDAMAGEDOUBLE))
          to->shield -= damage;
      if (to->shield<0)
          to->shield=0;
      
   }
   else
   {  

      int dmgLeft = damage - to->shield;
      if (useShield==false)
        dmgLeft = damage;
        to->shield = 0;
      if(dmgLeft < to->current.hp)
      {
         to->current.hp -= dmgLeft;
         
      }
      else
      {
         to->current.hp = 0;
         float lastTurn = lastTurnChance(to);
         random = float(rand())/float(RAND_MAX);
         if(random < LASTTURN && checkDebuffBool(to,NOLASTTURN)==false)
         {
            to->status = LASTTURN;
            to->ticks = (int)(to->original.moral / 10);
         }
         else
         {
             to->status = DEAD;
         }
         
      }
   }
   removeDebuff(from);
   removeAllBuff(from);
  //  cout<<"Out"<<endl;
   return damage;
   
}

void addShield(Player *player)
{
    for(int i=0; i<player->killers.size(); i++)
    {
        for(int j =0; j<player->killers[i]->cardsToUse.size(); j++)
        {
            switch (player->killers[i]->cardsToUse[j]->id)
            {
            case 7:
                {
                   Buff b;
                b.type=CARD7;
                b.turnsleft=0;
                player->killers[i]->buff.push_back(b);  
                break;}
            case 8:
            {
                Buff b;
            b.type=CARD8;
            b.turnsleft=0;
            player->killers[i]->buff.push_back(b);
            break;
            }
            case 9:
            {
                Buff b;
            b.type=CARD9;
            b.turnsleft=0;
            player->killers[i]->buff.push_back(b);
            break;
            }
            case 13:
            {
                Buff b;
            b.type=CARD13;
            b.turnsleft=0;
            player->killers[i]->buff.push_back(b);
            break;
            }
            case 38:
            {
                Buff b;
            b.type=CARD38;
            b.turnsleft=0;
            player->killers[i]->buff.push_back(b);
            break;
            }
            case 76:
            {
                 Buff b;
            b.type=CARD38;
            b.turnsleft=0;
            player->killers[i]->buff.push_back(b);
            break;
            }
            case 106:
            {
                Buff b;
                b.type = CARD106;
                b.turnsleft = 0;
                player->killers[i]->buff.push_back(b);
                break;
            }
            case 112:
            {
                Buff b;
                b.type = CARD112;
                b.turnsleft = 0;
                player->killers[i]->buff.push_back(b);
                break;
            }
            case 113:
            {
                  Buff b;
                b.type = CARD113;
                b.turnsleft = 0;
                player->killers[i]->buff.push_back(b);
                break;
            }
            case 125:
            {
                Buff b;
                b.type = CARD125;
                b.turnsleft = 0;
                player->killers[i]->buff.push_back(b);
                break;
            }
            case 133:
            {
                Buff b;
                b.type=CARD133;
                b.turnsleft=1;
                player->killers[i]->buff.push_back(b);
                break;
            }

            default:
                {
                break;
                }
            }
            float shieldRatio;
            shieldRatio=cardBonus(player->killers[i], player->killers[i]->cardsToUse[j],1);
            player->killers[i]->shield+=(int)(shieldRatio*player->killers[i]->cardsToUse[j]->shield);
        }
    }
}