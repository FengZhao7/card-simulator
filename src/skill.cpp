 #include "../include/function.h"
 #include <cstdlib> 

//0->this turn 1->1 turn 2->2 turns -1->permanent  buff/debuff turnsleft

 void applycard(Card* card, Killer* from, Killer* to, Player* killerOwner, Player* otherplayer, int turn, int order )
{
    //cout<<"Go in applyCard"<<" "<<card->id<< endl;
    switch (card->id)
    {
    case 3:
	    if (from->cardsToUse.size()>=2)
            if (otherplayer->energy>0)
            {
                otherplayer->energy--;
                addEnergy(killerOwner,1);

            }
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        
        break;
    case 4:
        {
            Buff b;
            b.type=CARD4;
            b.turnsleft=0;
            from->buff.push_back(b);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 5:
        {
            float extra=0;
            if (order==(killerOwner->killers.size()+otherplayer->killers.size()))
               extra=0.2;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);
        break;}
    case 6:
        Treat(120,from);
        //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 7:
         {
            Debuff d;
            d.type=LOSETWOHP;
            d.turnsleft=-1;
            to->debuff.push_back(d);
            
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 8:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 9:
         {
            
        //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 10:
        {float extra=0;
        if (from->shield==0)
           extra=0.2;
        dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);
        break;
        }
    case 11:
        {int num=dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        Treat(num,from);
        break;
        }
    case 12: 
        {
            int num = dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            if (to->cls == 'A')
                Treat(num, from);
            break;
        }
        break;
    case 13:
        {
            
            
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 14:
        Treat(120,from);
        //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 15:
        {float r=1;
        if (link(killerOwner, 'A', from))
            r=1.2;
        dealDamage(from,to,r,card,0,0,killerOwner,otherplayer,0);
        break;
        }
    case 16:
        {
            Buff b;
            b.type=BANPART;
            b.turnsleft=1;
            b.part=2;
            from->buff.push_back(b);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 17:
        removeAllDebuff(from);
        //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 18:
        {Killer *a=chooseFrontFriend(from,killerOwner->killers);
        if (a!=NULL)
           removeAllDebuff(a);
       //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);  
        break;
        }
    case 19:
        {
            Buff b;
            b.type=CARD19;
            b.turnsleft=1;
            from->buff.push_back(b);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            break;
            
        }
    case 20:
        {
            Buff b;
            b.type=CARD20;
            b.turnsleft=0;
            from->buff.push_back(b);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 21:
        {if (from->cardsToUse.size()>=2)
        {
            Killer* a=findKillerCls('C',otherplayer->killers);
            if (a!=NULL)
               dealDamage(from,a,1,card,0,0,killerOwner,otherplayer,0);
            else
               dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        }
        break;
        }
    case 22:
        {
            Killer* a=findKillerFast(otherplayer->killers);
           // a->Show();
        dealDamage(from,a,1,card,0,0,killerOwner,otherplayer,0);
        //cout<<"OK"<<endl;
        break;}
    case 23:
        treatFirstRow(killerOwner->killers,175);
        //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 24:
        
        treatFirstRow(killerOwner->killers,270);
        //cout<<"OK"<<endl;
        //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 25:
        if (checkCardTwoDifferent(card, from->cardsToUse))
           dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,1);
        else
           dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 26:
        {float r=1;
        if (checkCardSame(card, from->cardsToUse))
            r=1.2;
        dealDamage(from,to,r,card,0,0,killerOwner,otherplayer,0);
        break;
        }
    case 27:
        {
            float extra=0;
            if (from->status==LASTTURN)
               extra=0.5;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);
        break;}
    case 28:
    {
        dealDamage(from,to,1,card, 0 ,0,killerOwner,otherplayer,0);
        break;
    }
    case 29:
        if ((float)from->current.hp/(float)from->original.hp<0.3)
        {
            Debuff d;
            d.type=GETDOUBLEDAMAGE;
            d.turnsleft=0;
            to->debuff.push_back(d);
        }
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 30:
        if (otherplayer->energy>=1)
            otherplayer->energy--;
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 31:
        addEnergy(killerOwner,1);
        //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break; 
    case 32:
        {float r=1;
        if (checkCardSame(card, from->cardsToUse))
            r=1.2;
        dealDamage(from,to,r,card,0,0,killerOwner,otherplayer,0);
        break;
        }
    case 33:
        if (link(killerOwner,'A', from) && checkCard( 'A', from->cardsToUse) )
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0.2);
        else
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 34:
        if (link(killerOwner,'A', from) && checkCard( 'A', from->cardsToUse) )
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0.2);
        else
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 35:
        dealDamage(from,to,1,card,0,1.5,killerOwner,otherplayer,0);
        break;
    case 36:
    {   
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    }
    case 37:
        {
            Buff b;
            b.type=CARD37;
            b.turnsleft=0;
            from->buff.push_back(b);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 38:
        {
           
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 39:
        {   
            if(to->status == LASTTURN)
            {
                for(int i=0; i<killerOwner->killers.size(); i++)
                {
                    Buff b;
                    b.type = MORAL;
                    b.turnsleft = 1;
                    killerOwner->killers[i]->buff.push_back(b);
                    Killer * killer = killerOwner->killers[i];
                    double bonus = killer->original.moral * 0.2;
                    killer->current.moral -= int(bonus);
                }
            }
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            break;
        }
        
    case 40:
        if (from->cardsToUse.size()>=2)
            if (otherplayer->energy>0)
            {
                otherplayer->energy--;
                addEnergy(killerOwner,1);

            }
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 41:
    {   
        int dmg = dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        if(to->cls == 'A')
        {
            from->shield+=dmg;
        }
        break;  
    }
    case 42:
        {
            //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Buff b;
            b.type=MORAL;
            b.turnsleft=2;
            applyBuff(from, b);   
        }
        break;
    case 43:
        if (from->cardsToUse.size()>=2)
            from->shield*=1.2;
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 44:
        if (otherplayer->killers.size()>=2)
            dealDamage(from,findKillerDistance(otherplayer->killers,1),1,card,0,0,killerOwner,otherplayer,0);
        else
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 45:
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 46:
        if (to->cls=='D' || to->cls=='C' || to->cls=='H')
           getCards(killerOwner,1);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 47:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Debuff d;
            d.type=ATTACK;
            d.turnsleft=2;
            applyDeBuff(from, d);  
        break;}
    case 48:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Debuff d;
            d.type=ATTACK;
            d.turnsleft=-1;
            applyDeBuff(to, d);   
        break;}
    case 49:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Debuff d;
            d.type=GETATTACKFIRST;
            d.turnsleft=1;
            applyDeBuff(from, d);   
        break;}   
    case 50:
        {float r=1;
        if (checkCardSame(card, from->cardsToUse))
            r=1.2;
        dealDamage(from,to,r,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 51:
        {
            Debuff d;
            d.type=CANTCRITIC;
            d.turnsleft=2;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;} 
    case 52:
        {if ((float)from->current.hp/(float)from->original.hp<0.5)
            {
                Killer* a=findKillerCls('F',otherplayer->killers);
                if (a!=NULL)
                   dealDamage(from,a,1,card,0,0,killerOwner,otherplayer,0);
                else
                   dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            }   
        break;} 
    case 53:
        {
            float extra=0;
            if (order==0)
                extra=0.2;
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 54:
        dealDamage(from,findKillerFast(otherplayer->killers),1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 55:
        {
            Buff b;
            b.type=BANPART;
            b.turnsleft=1;
            b.part=1;
            from->buff.push_back(b);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 56:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Debuff d;
            d.type=MORAL;
            d.turnsleft=2;
            applyDeBuff(to, d); 
        break;} 
    case 57:
        from->current.hp-=(float)from->original.hp*0.3;
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 58:
        {   
            for(int i =0; i<from->debuff.size(); i++)
            {
                applyDeBuff(to, from->debuff[i]);
            }
            removeAllDebuff(from);
        break;}
    case 59:
        {if ((float)from->current.hp/(float)from->original.hp<0.5)
            {
                Killer* a=findKillerCls('D',otherplayer->killers);
                if (a!=NULL)
                   dealDamage(from,a,1,card,0,0,killerOwner,otherplayer,0);
                else
                   dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            }   
        break;}
    case 60:
        {
            if (to->status==LASTTURN)
            {
                Killer* a=findKillerNoStatus(LASTTURN,otherplayer->killers);
                if (a!=NULL)
                   dealDamage(from,a,1,card,0,0,killerOwner,otherplayer,0);
                else
                   dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 

            }
            else
            {
                dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            }
        break; }
    case 61:
        {
            Debuff d;
            d.type=NOLASTTURN;
            d.turnsleft=2;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;} 
    case 62:
        from->shield+=from->debuff.size()*0.2*(float)from->shield;
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 63:
        if (from->debuff.size()!=0)
           dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 64:
        if (otherplayer->killers.size()>=2)
            dealDamage(from,findKillerDistance(otherplayer->killers,1),1,card,0,0,killerOwner,otherplayer,0);
        else
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 65:
        {
            Debuff d1;
            d1.type=CANTATTACK;
            d1.turnsleft=1;
            to->debuff.push_back(d1);

            Debuff d2;
            d2.type=CARD65;
            d2.turnsleft=0;
            from->debuff.push_back(d2);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 66:
        {
            //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Buff b;
            b.type=ATTACK;
            b.turnsleft=-1;
            applyBuff(from, b);          
        break;}
    case 67:
        {float r=1;
        for (auto a: killerOwner->killers )
           if (a!=from && checkCardSame(card, a->cardsToUse))
                r=1.2;
        dealDamage(from,to,r,card,0,0,killerOwner,otherplayer,0);
        break;
        }
    case 68:
        {
            Debuff d;
            d.type=NOSHIELD1;
            d.turnsleft=-1;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;} 
    case 69:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            if (to->cls=='A' || to->cls=='E' || to->cls=='H')
            {
                Buff b;
                b.type=ATTACK;
                b.turnsleft=-1;
                applyBuff(from,b);
            }
            
        break;}  
    case 70:
        {
            if ((float)from->current.hp/(float)from->original.hp<0.5 && to->current.hp== to->original.hp)
            {
                Killer* a=findKillerInjured(otherplayer->killers);
                if (a!=NULL)
                   dealDamage(from,a,1,card,0,0,killerOwner,otherplayer,0); 
                else
                   dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);

            }
            else
            {
                dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            }
        break;} 
    case 71:
        if ((float)from->current.hp/(float)from->original.hp<0.5)  
           dealDamage(from,to,1,card,0.2,0,killerOwner,otherplayer,0);
        break;
    case 72:
        {   float extra=0;
            if (from->cardsToUse.size()>=2 && from->cardsToUse[0]!=from->cardsToUse[1])
               extra=0.2;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);         
        break;}
    case 73:
        {
            Buff b;
            b.type=CARD73;
            b.turnsleft=0;
            from->buff.push_back(b);
            //dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;} 
    case 74:
        {   
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            if(to->status == LASTTURN)
            {
                to->status =DEAD;
            }
            break; 
        }
        
    case 75:
        if (to->status==LASTTURN)
        {
            killerDead(otherplayer, to);
        }
        else
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        }
        break; 
    case 76:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;} 
    case 77:
        if (to->status==LASTTURN)
           getCards(killerOwner,1);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 78:
        {
            Debuff d;
            d.type=NOLASTTURN;
            d.turnsleft=2;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}  
    case 79:
        {
            if (to->cls=='B' || to->cls=='F' || to->cls=='I')
            {
                Buff b;
                b.type=ATTACK;
                b.turnsleft=-1;
                from->buff.push_back(b);
            }
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;} 
    case 80:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            if (from->shield==0)
            {
                Buff b;
                b.type=ATTACK;
                b.turnsleft=-1;
                applyBuff(from, b);
            }
            
        break;} 
    case 81:
        {
            float extra=0;
            if (order==0)
               extra=0.2;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0); 
        break;}
    case 82:
        {
            Debuff d;
            d.type=CANTCRITIC;
            d.turnsleft=2;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 83:
        {
            float extra=0;
            if (to->cardsToUse.size()==0)
               extra=0.3;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0); 
        break;}
    case 84:
        {
            if (checkCardTwoDifferent(card, from->cardsToUse) && to->cardsToUse.size()!=0)
            {
                Killer* a=findKillerFree(otherplayer->killers);
                dealDamage(from,a,1,card,0,0,killerOwner,otherplayer,0); 
            }
            else
            {
                dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
            }
        break;}
    case 85:
        from->shield+=from->shield*1.3;
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;  
    case 86:
        {
            int num=dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Treat(num, from); 
        }
        break;
    case 87:
        dealDamage(from,findKillerDistance(otherplayer->killers,2),1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 88:
    {   
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    }
    case 89:
    {   
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    }
    case 90:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            if (checkCardSameCls(card, from->cardsToUse))
            {
                Buff b;
                b.type=SPEED;
                b.turnsleft=2;
                applyBuff(from,b);
            }
             
        break;}
    case 91:
        {
            if (checkCardTwoDifferent(card,from->cardsToUse))
            {
                Debuff d;
                d.type=NOSHIELD1;
                d.turnsleft=0;
                to->debuff.push_back(d);
            }
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;}
    case 92:
        for (auto a: killerOwner->killers)
        {
            if (a->location==from->location-1 || a->location==from->location+1 || a->location==from->location-2 ||  a->location==from->location+2)
               a->shield+=from->shield*0.15;
        }
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 93:
        {
            float extra=0;
            if (turn > 4)
               extra=0.5;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);
        break;}
    case 94:
        if (to->current.speed>from->current.speed)
           addEnergy(killerOwner,1);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 95:
        dealDamage(from,findKillerDistance(otherplayer->killers,2),1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 96:
        {
            float extra=0;
            if (to->current.speed>from->current.speed)
                extra=0.3;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);
        break;}
    case 97:
        if (from->shield==0)
           getCards(killerOwner,1);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 98:
        {
            for (auto d: to->debuff)
            {
                if (d.type==LOSETWOHP)
                {
                    Debuff d;
                    d.type=ATTACK;
                    d.turnsleft=-1;
                    to->debuff.push_back(d);
                    break;
                }
            }
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 99:
        {
           int dmg = dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
           if(to->cls == 'D')
             Treat(dmg, from);
        break;}
    case 100:
        {
            if (from->cardsToUse.size()>=3)
            {
                dealDamage(from,findKillerLeastShield(otherplayer->killers),1,card,0,0,killerOwner,otherplayer,0);
            }
            else
                dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 101:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Debuff d;
            d.type=SPEED;
            d.turnsleft=2;
            applyDeBuff(to,d);         
        break;}
    case 102:
        if (checkCard('A',from->cardsToUse))
           from->shield+=card->shield;
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 103:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Debuff d;
            d.type=SPEED;
            d.turnsleft=2;
            applyDeBuff(to,d); 
        
        break;}
    case 104:
        if (to->buff.size()>0)
           addEnergy(killerOwner,1);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 105:
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 106:
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 107:
        {
            float extra=0;
            if (checkCardSameCls(card,from->cardsToUse))
                extra=0.2;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);  
        break;}
    case 108:
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 109:
        {
            Buff b;
            b.type=CARD109;
            b.turnsleft=-1;
            from->buff.push_back(b);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);  
        break;}
    case 110:
        {
            Debuff d;
            d.type=LOSETWOHP;
            d.turnsleft=-1;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 111:
        {
            Debuff d;
            d.type=LOSEPRIORITY;
            d.turnsleft=0;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 112:
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 113:
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 114:
        if (linkSameCard(killerOwner,from,card))
           addEnergy(killerOwner,1);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);  
        break;
    case 115:
        {
            float extra=0;
            if (to->debuff.size()>0)
               extra=0.3;
            dealDamage(from,to,1,card,extra,0,killerOwner,otherplayer,0);  
        break;}
    case 116:
        {
            int num=dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Treat(num,from);
        break;}
    case 117:
        if (checkCard('A',from->cardsToUse))
            addEnergy(killerOwner,1);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);  
        break;
    case 118:
        if (to->shield>0)
            dealDamage(from,to,1.3,card,0,0,killerOwner,otherplayer,0); 
        else
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 119:
        if (to->cls=='F')
            dealDamage(from,to,1.5,card,0,0,killerOwner,otherplayer,0); 
        else
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 120:
        {
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
            Debuff d;
            d.type=ATTACK;
            d.turnsleft=-1;
            applyDeBuff(to, d);
            
        break;}
    case 121:
        {
            if (from->cardsToUse.size()>=2)
            {
                Debuff d;
                d.type=LOSETWOHP;
                d.turnsleft=-1;
                to->debuff.push_back(d);

            }
            
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;}
    case 122:
        throwCards(otherplayer);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 123:
        {
            Debuff d;
            d.type=NOTREAT;
            d.turnsleft=0;
            to->debuff.push_back(d);
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;}
    case 124:
        {
            if (to->shield>0)
            {
                Debuff d;
                d.type=CANTATTACK;
                d.turnsleft=0;
                to->debuff.push_back(d);
            }
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;}
    case 125:
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 126:
        {
            if (from->cardsToUse.size()>=2)
            {
                Debuff d;
                d.type=CANTATTACK;
                d.turnsleft=2;
                to->debuff.push_back(d);
            }
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;}
    case 127:
        {
             Debuff d;
             d.type=SHIELDDAMAGEDOUBLE;
             d.turnsleft=0;
             to->debuff.push_back(d);
             dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;}
    case 128:
        throwCards(otherplayer);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        break;
    case 129:
        if (from->status==LASTTURN)
        {
             dealDamage(from,to,1,card,1,0,killerOwner,otherplayer,0);
             killerDead(killerOwner, to);

        }
        else
        {
             dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        }
        break;
    case 130:
        {
             Debuff d;
             d.type=LOSEPRIORITY;
             d.turnsleft=1;
             to->debuff.push_back(d);
             dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;}
    case 131:
        if (from->cardsToUse.size()>=2)
            dealDamage(from,to,2,card,0,0,killerOwner,otherplayer,0); 
        else 
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
        break;
    case 132:
        {
             dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0); 
             Debuff d;
             d.type=SPEED;
             d.turnsleft=2;
             applyDeBuff(to, d);            
        break;}
    case 133:
        { 
          dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
          break;}
    case 134:
        if (from->cardsToUse.size()>=2)
            dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);
        dealDamage(from,to,1,card,0,0,killerOwner,otherplayer,0);  
        break;
    default:
        break;
    }
    for(int i=0; i<killerOwner->killers.size(); i++)
    {
        if(killerOwner->killers[i]->status == LASTTURN)
        {
            killerOwner->killers[i]->ticks -=1;
            if(killerOwner->killers[i]->ticks <=0)
             killerOwner->killers[i]->status = DEAD;
        }
    }
    for(int i =0; i<otherplayer->killers.size(); i++)
    {
        if(otherplayer->killers[i]->status == LASTTURN)
        {
            if(otherplayer->killers[i] != to)
            {
                otherplayer->killers[i]->ticks -=1;
                if(otherplayer->killers[i]->ticks <=0)
                {
                    otherplayer->killers[i]->status = DEAD;
                }
            }
        }
    }
    //cleanDeadKiller(killerOwner->killers);
    //cleanDeadKiller(otherplayer->killers);

    for (int i=0; i<killerOwner->killers.size(); i++)
    {
        if (killerOwner->killers[i]->status == DEAD || killerOwner->killers[i]->current.hp<=0)
        {   killerOwner->killers.erase(killerOwner->killers.begin()+i, killerOwner->killers.begin()+i+1);
            i--;
        }
    }

    for (int i=0; i<otherplayer->killers.size(); i++)
    {
        if (otherplayer->killers[i]->status == DEAD || otherplayer->killers[i]->current.hp<=0)
        {   otherplayer->killers.erase(otherplayer->killers.begin()+i, otherplayer->killers.begin()+i+1);
            i--;
        }
    }
    

}

void cleanDeadKiller(vector<Killer*> killer)
{
     for (int i=0; i<killer.size(); i++)
    {
        if (killer[i]->status == DEAD)
        {   killer.erase(killer.begin()+i, killer.begin()+i+1);
            i--;
        }
    }
}

//Treat
void Treat(int num, Killer *A)
{
    if (checkDebuffBool(A,NOTREAT)==false)
    {
        A->current.hp+=num;
        A->current.hp=min(A->original.hp,A->current.hp);

    }
    
    
}

//energy++
void addEnergy(Player *p, int num)
{
    p->energy+=num;
    if (p->energy>10)
        p->energy=10;
}

//check whether link to class A card
bool link(Player *p, char cls, Killer *killer)
{
    for (auto a: p->killers)
    {
        if (a!=killer)
        {
            if (checkCard(cls,a->cardsToUse))
                return true;
        }
    }
    return false;

}

bool linkSameCard(Player *p, Killer *killer, Card *card)
{
    for (auto a: p->killers)
    {
        if (a!=killer)
        {
            if (checkCardSame(card,a->cardsToUse))
                return true;
        }
    }
    return false;

}

//重构
//check whether class A card in the card group
bool checkCard(char cls, vector<Card*> card)
{
    for (auto c: card)
    {
        if (c->cls==cls )
           return true;
    }
    return false;
}


bool checkCardSame(Card *card, vector<Card*> card_vector )
{
    for (auto c: card_vector)
    {
        if (c->id==card->id && c!=card)
           return true;
    }
    return false;
}

bool checkCardSameCls(Card *card, vector<Card*> card_vector )
{
    for (auto c: card_vector)
    {
        if (c->cls==card->cls && c!=card)
           return true;
    }
    return false;
}

bool checkCardTwoDifferent(Card *card, vector<Card*> card_vector )
{
    int count=0;
    for (auto c: card_vector)
    {
        if ( c->id!=card->id && c!=card)
           count++;
    }
    if (count>=2)
       return true;
    else 
       return false;
}


/*bool checkLastFight(vector<Killer*> killer1, vector<Killer*> killer2, Killer *own)
{
    for (int i=0;i<killer1.size();i++)
    {
        if (killer1[i]->current.speed<own->current.speed)
           return false;
    }
    for (int i=0;i<killer2.size();i++)
    {
        if (killer2[i]->current.speed<own->current.speed)
           return false;
    }
    return true;

}*/

Killer *chooseFrontFriend (Killer *own, vector<Killer*> killer )
{
    int l=own->location;
    while(l>3)
    {
        l=l-3;
        Killer* a=findKillerLocation(l,killer);
        if(a!=NULL)
        {
            return a;
        }

    }
    return NULL;


}
// 重构

Killer *findKillerLocation(int l, vector<Killer*> killer )
{
    for(auto a: killer)
    {
        if (a->location==l)
           return a;
    }
    return NULL;

}


Killer *findKillerCls(char c, vector<Killer*> killer )
{
    for(auto a: killer)
    {
        if (a->cls==c)
           return a;
    }
    return NULL;

}

Killer *findKillerNoStatus(killerStatus s, vector<Killer*> killer )
{
    for(auto a: killer)
    {
        if (a->status!=s)
           return a;
    }
    return NULL;

}


Killer *findKillerFree( vector<Killer*> killer )
{
    
    for(auto a: killer)
    {
        if (a->cardsToUse.size()==0)
        {
            return a;
        }
          
    }
    return NULL;

}


Killer *findKillerInjured(vector<Killer*> killer )
{
    for(auto a: killer)
    {
        if (a->current.hp<a->original.hp)
           return a;
    }
    return NULL;

}

Killer *findKillerLeastShield(vector<Killer*> killer )
{
    int s=killer[0]->shield;
    Killer* res=killer[0];
    for(auto a: killer)
    {
        if (a->shield<s)
        {
            s=a->shield;
            res=a;

        }
    }
    return res;

}


Killer *findKillerFast( vector<Killer*> killer )
{
    int s=0;
    Killer* res;
    //cout<<"Go in findKillerFast"<<endl;
    //cout<<killer.size()<<endl;
    for(int i=0; i<killer.size();i++)
    {
        cout<<killer[i]->current.speed<<endl;
        if (killer[i]->current.speed>s)
        {
            res=killer[i];
            s=killer[i]->current.speed;
        }
          
    }
    
    return res;

}





bool compareLocation(const Killer* a, const  Killer* b)
{
   return a->location < b->location;
}

Killer *findKillerDistance( vector<Killer*> killer,int num )
{  //0 first  1 second 2 last
    sort(killer.begin(),killer.end(),compareLocation);
    if (num==0)
       return killer[0];
    else if (num==1)
       return killer[1];
    else
       return killer[killer.size()-1];
}

void treatFirstRow(vector<Killer*> killer, int num)
{
    //cout<<"In 24"<<endl;
    //cout<<killer.size()<<endl;
    
    sort(killer.begin(),killer.end(),compareLocation);
    //cout<<killer[0]<<endl;
    Treat(num,killer[0]);
     cout<<"Out 24"<<endl;
    if ((killer[0]->location==2 || killer[0]->location==5) && killer.size()>=2)
    {
        if (killer[1]->location==killer[0]->location+1)
           Treat(num,killer[1]); 
    }

}

void throwCards(Player *p)
{
    int cardNum=0;
    for (int i=0;i<p->killers.size();i++)
    {
        cardNum+=p->killers[i]->cardsCanUse.size();
    }

    if (cardNum>0)
    {
        int i=rand() % p->killers.size();
        while (p->killers[i]->cardsCanUse.size()==0)
        {
            i=rand() % p->killers.size();
        }

        int j=rand() % p->killers[i]->cardsCanUse.size()+1;
        p->killers[i]->cardsCanUse.erase(p->killers[i]->cardsCanUse.begin()+j); 
    }
}
