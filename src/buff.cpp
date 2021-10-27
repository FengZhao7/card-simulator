
#include "../include/function.h"

// MORAL ATTACK SPEED   


void removeAllBuff(Killer *killer)
{
    for (int i=0;i < killer->buff.size();i++)
    {
        if(killer->buff[i].type == MORAL)
        {
            double bonus = killer->original.moral * 0.2;
            killer->current.moral -= int(bonus);
        }
        else if (killer->buff[i].type == ATTACK)
        {
            killer->current.attack -= 0.2;
        }
        else if (killer->buff[i].type == SPEED)
        {
           double bonus = killer->original.speed  *0.2;
           killer->current.speed -= int(bonus);
        }

        if (killer->buff[i].type<=2)
        {
            killer->buff.erase(killer->buff.begin()+i, killer->buff.begin()+i+1);
            i--;
        }

    }
}
void applyBuff(Killer *killer, Buff buff)
{   
    killer->buff.push_back(buff);
    if(buff.type == MORAL)
    {
        double bonus = killer->original.moral * 0.2;
        killer->current.moral += int(bonus);
    }
    else if (buff.type == ATTACK)
    {
        killer->current.attack += 0.2;
    }
    else
    {
        double bonus = killer->original.speed  *0.2;
        killer->current.speed += int(bonus);
    }
}

// MORAL ATTACK SPEED GETATTACKFIRST
void removeDebuff(Killer *killer)
{
    for (int i=0;i < killer->debuff.size();i++)
    {
        if(killer->debuff[i].type == MORAL)
        {
           double bonus = killer->original.moral * 0.2;
           killer->current.moral += int(bonus);
        }
        else if (killer->debuff[i].type == ATTACK)
        {
           killer->current.attack += 0.2;
        }
        else if (killer->debuff[i].type == SPEED)
        {
           double bonus = killer->original.speed  *0.2;
           killer->current.speed += int(bonus);
        }

        if (killer->debuff[i].type<=2)
        {
            killer->debuff.erase(killer->debuff.begin()+i, killer->debuff.begin()+i+1);
            i--;

        }
        
        
    }
  
}

void removeAllDebuff(Killer *killer)
{
    removeDebuff(killer);
    for (int i=0;i<killer->debuff.size();i++)
    {
        if (killer->debuff[i].type<=12)
        {
            killer->debuff.erase(killer->debuff.begin()+i, killer->debuff.begin()+i+1);
            i--;

        }
    }
}

void applyDeBuff(Killer *killer, Debuff debuff)
{   
    killer->debuff.push_back(debuff);
    if(debuff.type == MORAL)
    {
        double bonus = killer->original.moral * 0.2;
        killer->current.moral -= int(bonus);
    }
    else if (debuff.type == ATTACK)
    {
        killer->current.attack -= 0.2;
    }
    else if (debuff.type == SPEED)
    {
        double bonus = killer->original.speed  *0.2;
        killer->current.speed -= int(bonus);
    }
  
    
    
}



vector<Killer*> checkDebuff12(vector<Killer*> killer)
{
    int last=killer.size();
    for (int i=0;i<last;i++)
    {
        for (auto d: killer[i]->debuff)
        {
            if (d.type==LOSEPRIORITY)
            {
                
                killer.push_back(killer[i]);
                killer.erase(killer.begin()+i);
                last--;
                break;

            }
        }
    }
    return killer;

}

void checkBuffCard7 (Killer *from, Killer *to)
{
    for (int i=0;i<from->buff.size();i++)
    {
        if (from->buff[i].type==CARD7)
        {
            Debuff d;
            d.type=LOSETWOHP;
            d.turnsleft=0;
            to->debuff.push_back(d);
        }
    }
}
bool checkBuffCard106 (Killer *to)
{
     for (int i=0;i<to->buff.size();i++)
    {
        if (to->buff[i].type==CARD106)
        {
           return true;
        }
    }
    return false;
}
bool checkBuffCard112 (Killer *to)
{
     for (int i=0;i<to->buff.size();i++)
    {
        if (to->buff[i].type==CARD112)
        {
           return true;
        }
    }
    return false;
}

bool checkBuffCard113 (Killer *to)
{
     for (int i=0;i<to->buff.size();i++)
    {
        if (to->buff[i].type==CARD113)
        {
           return true;
        }
    }
    return false;
}


bool checkBuffCard125(Killer *to)
{
     for (int i=0;i<to->buff.size();i++)
    {
        if (to->buff[i].type==CARD125)
        {
           return true;
        }
    }
    return false;
}




void checkBuffCard8 (Killer *from, Killer *to, Player *opp)
{
    if (from->cls=='D' && to->shield>=0)
    {
         for (int i=0;i<to->buff.size();i++)
        {
            if (to->buff[i].type==CARD8  )
            {
                addEnergy(opp,1);
            
            }
        }

    }
   


}


void checkBuffCard13 (Card *card, Killer *to, Player *opp)
{
    if (card->cls=='B' || card->cls=='F' || card->cls=='I')
    {
         for (int i=0;i<to->buff.size();i++)
        {
            if (to->buff[i].type==CARD13)
            {
                getCards(opp,1);
            
            }
        }

    }

}

void checkBuffCARD38  (Killer *to)
{
    //cout<<"In BUff 38"<<endl;
    //cout<<to<<endl;
    
    //cout<<to->buff.size()<<endl;
  
    for (unsigned int i=0; i<to->buff.size();i++)
    {
       // to->buff[i].Show();
        if (to->buff[i].type==CARD38)
        {
            Buff b1;
            b1.type=SPEED;
            b1.turnsleft=2;
            to->buff.push_back(b1);
            break;
          
        }
    }
    //cout<< to->buff.size()<<endl;
    //cout<<"Out BUff 38"<<endl;

}

void checkDebuffCARD65  (Killer *to)
{
     for (unsigned int i=0; i<to->debuff.size();i++)
    {
        if (to->debuff[i].type==CARD65 && to->shield>0)
        {
            Debuff d;
            d.type=CANTATTACK;
            d.turnsleft=0;
            to->debuff.push_back(d);
            break;
        }
    }

}

void checkBuffCARD109(Killer *own)
{
    for (unsigned int i=0;i< own->buff.size();i++)
    {
        if (own->buff[i].type==CARD109)
        {
            own->shield+=20;
            break;
        }
    }

}



void checkDebuff9(Killer *k)
{
    for (unsigned int i=0; i< k->debuff.size();i++)
    {
        if (k->debuff[i].type==LOSETWOHP)
        {   
            if(k->current.hp <=2)
            {
                k->status = DEAD;
            }
            else
            k->current.hp-=2;
            break;
        }
    }
}
void checkBuffCARD133 (Killer *from, Killer *to)
{
    for (int i=0;i<from->buff.size();i++)
    {
        if (from->buff[i].type==CARD133)
        {
            Debuff d;
            d.type=CANTCLOSECOMBAINT;
            d.turnsleft=0;
            to->debuff.push_back(d);
            break;

        }
    }
}
bool checkDebuffCANTCLOSECOMBAINT(Card *card, Killer *from)
{
    for (int i=0;i<from->debuff.size();i++)
    {
        if (from->debuff[i].type==CANTCLOSECOMBAINT && card->range==0)
        return true;
    }
    return false;
}

bool checkBuffCARD19( Card *card, Killer *to)
{
    for (int i=0;i<to->buff.size();i++)
    {
        
        if (to->buff[i].type==CARD19 && card->range==1)
        {  
            return true;
        }
    }
    return false;
}

bool checkBuffBANPART (Card *card, Killer *to)
{

    for (int i=0;i<to->buff.size();i++)
    {
        if (to->buff[i].type==BANPART && to->buff[i].turnsleft==0 && card->part==to->buff[i].part)
            return true;
    } 
    return false;

}

bool checkBuffCARD20 (Card *card, Killer *to, Player *opp)
{
    if (opp->killers.size()>=2 && card->cls=='D')
    {
        for (int i=0;i<to->buff.size();i++)
        {
            if (to->buff[i].type==CARD20)
            {
                return true;
            }
        }

    }
    return false;


}
bool  checkBuffCARD37 (Card *card, Killer *from, Player *own)
{
    if (card->cls=='F')
    {
        for (auto a: own->killers)
        {
            if (a!=from)
            {
                for (auto b:a->buff)
                {
                    if (b.type==CARD37)
                       return true;
                }
            }
        }
    }
    return false;
}

bool  checkBuffCARD73 (Killer *to)
{
   for (auto b: to->buff)
    {
        if (b.type==CARD73)
        {
            return true;
        }
    }
    return false;
}

bool checkDebuffNOTREAT(Killer *own)
{
    for (auto d: own->debuff)
    {
        if (d.type==NOTREAT)
           return true;
    }
    return false;

}

//NOTREAT  NOLASTTURN (debuff 3)  CANTATTACK(debuff 4)  CANTCRITIC (debuff 6)
bool checkDebuffBool(Killer *k, property p)
{
    for (auto d: k->debuff)
    {
        if (d.type==p)
           return true;
    }
    return false;

}

// just for once
// SHIELDDAMAGEDOUBLE (debuff 5) GETDOUBLEDAMAGE(debuff 7) NOSHIELD1(debuff 10)
bool checkDebuffBoolNext(Killer *k, property p)
{
    vector<Debuff>::iterator it;
    for(it=k->debuff.begin();it!=k->debuff.end();++it)
    {
        if((*it).type ==p)
        {
            it=k->debuff.erase(it);
            return true;
           
        }

    }
    return false;

}

Killer *checkDebuffGETATTACKFIRST( Player *opp )
{
    
    
    for(auto k: opp->killers)
    {
        for (auto d: k->debuff)
        {
            if (d.type==GETATTACKFIRST)
                return k;
        }
          
    }
    return NULL;

}


void reduceTurnBuffandDebuff(Player *p)
{
    for (int i=0;i<p->killers.size();i++)
    {
        for (int j=0;j<p->killers[i]->buff.size();j++)
        {
            if (p->killers[i]->buff[j].turnsleft==0)
            {
                p->killers[i]->buff.erase(p->killers[i]->buff.begin()+j, p->killers[i]->buff.begin()+j+1);
                j--;
            }
            else if (p->killers[i]->buff[j].turnsleft>0)
            {
                p->killers[i]->buff[j].turnsleft--;
            }
        }

        for (int j=0;j<p->killers[i]->debuff.size();j++)
        {
            if (p->killers[i]->debuff[j].turnsleft==0)
            {
                p->killers[i]->debuff.erase(p->killers[i]->debuff.begin()+j, p->killers[i]->debuff.begin()+j+1);
                j--;
            }
            else if (p->killers[i]->debuff[j].turnsleft>0)
            {
                p->killers[i]->debuff[j].turnsleft--;
            }
        }
    }
}





