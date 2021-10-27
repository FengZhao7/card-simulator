#include "../include/function.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

// 给killers 发放可以用的卡牌
void getCards (Player *owner,int num)
{
  
   if (owner->cards.size()==0)
   {
      // 24张卡牌全部用完，重新将使用过的卡牌使用  cardsReject：弃卡堆 cards：卡堆
      owner->cards=owner->cardsReject;
      random_shuffle(owner->cards.begin (), owner->cards.end ());
      if(owner->cards.size() !=0)
      {
      for (int i=0;i<50;i++)
      {
         swap(owner->cards[rand()%owner->cards.size()],owner->cards[rand()%owner->cards.size()]);
      }
      }
      owner->cardsReject.erase( owner->cardsReject.begin(),owner->cardsReject.end());
      
   }
  
   // 从已经被乱序过的卡堆中，发num张卡牌
   for (int i=0;i<num;i++)
   {
      int flag=0;
      for (int j=0;j<owner->killers.size();j++)
      {
         if (owner->killers[j]->id==owner->cards[i]->id_host)
         {
            owner->killers[j]->cardsCanUse.push_back(owner->cards[i]);
            flag=1;

         }
      }
      if (flag==0)
         num++;
      if (num>=owner->cards.size())
          break;
      
   }
   
   if (num>=owner->cards.size())
       num=owner->cards.size();
   owner->cards.erase( owner->cards.begin(),owner->cards.begin()+num);
   
   
}


void cardChoosen(Player *player)
{  
   for (int i=0;i<player->killers.size();i++)
   {
      string s;
      string buf;
      cout<<"For 打手"<<player->killers[i]->id
      <<", choose cards (Press Enter to finish input):"<<endl;
     
      getline(cin,s);
      
      s=s+' ';
      
      
      string temp="";
      int k=0;
      //while()
      //for (int j=0;j<s.size();j++)
      for (int k=0;k<s.size();k++)
      {
         if (s[k]==' ')
         {
            int j=temp.size();
            int a=0;
            while(j>0)
            {
               a+=(temp[temp.size()-j]-'0')*pow(10,j-1);
               j--;

            }
            if (player->energy>0)
            {
               
               vector<Card*> ::iterator it;
               for (it= player->killers[i]->cardsCanUse.begin();it!=player->killers[i]->cardsCanUse.end();)
               {  
                  if ((*it)->id==a)
                  {
                     player->killers[i]->cardsToUse.push_back(*it);
                     //player->cardsReject.push_back(*it);
                     it=player->killers[i]->cardsCanUse.erase(it);
                     player->energy-=(*it)->energy;
                     break;
                  }
                  else
                    ++it;
               }

            }
            temp="";
         }
         else
            temp=temp+s[k];
        
            
         
      }

          
         

      
   }

 

}


void cardsRejectandClean(Player *p)
{
   for (int i=0;i<p->killers.size();i++)
   {
      p->cardsReject.insert(p->cardsReject.end(), p->killers[i]->cardsToUse.begin(), p->killers[i]->cardsToUse.end());
      p->killers[i]->cardsToUse.erase( p->killers[i]->cardsToUse.begin(),p->killers[i]->cardsToUse.end());
      //cout<<p->killers[i]->cardsToUse.size()<<" ";
   }
}

bool judgeFinish(Player *owner, Player *opp)
{
   if (opp->killers.empty() && owner->killers.empty())
   {
      cout<<"Draw"<<endl;
      return true;
   }
   if (opp->killers.empty())
   {
      cout<<"Victory"<<endl;
      return true;
   }
   else if (owner->killers.empty())
   {
      cout<<"Defeated"<<endl;
      return true;
   }
   return false;
}

bool comparePirority(const Killer* a, const  Killer* b)
{
   return a->pirority < b->pirority;
}

Killer* calculatePirority(Player *opp)
{
   sort(opp->killers.begin(),opp->killers.end(),comparePirority);
   return opp->killers[0];
   
}



void killerDead(Player *p, Killer *deadKiller)
{
   vector<Killer*>::iterator it;
   for(it=p->killers.begin();it!=p->killers.end();++it)
   {
      if(*it == deadKiller)
      {
            it=p->killers.erase(it);
            break;
      }

   }

}
void lastJudgeDebuffandBuff (Player *p)
{
   int card4Flag=0;

      for (int i=0;i<p->killers.size();i++)
      {
         for (int j=0;j<p->killers[i]->buff.size();j++)
         {
            if (p->killers[i]->buff[j].turnsleft==0)
            {
               p->killers[i]->buff.erase(p->killers[i]->buff.begin()+j, p->killers[i]->buff.begin()+j+1);
               j--;
            }
            else
            {
               if (p->killers[i]->buff[j].turnsleft>0)
                   p->killers[i]->buff[j].turnsleft--;
            //check card4
               if (p->killers[i]->buff[j].type==CARD4 && card4Flag==0)
               {
                  addEnergy(p, 1);
                  card4Flag=1;
               }

            //check card9
               if (p->killers[i]->buff[j].type==CARD9 && p->killers[i]->shield>0)
               {
                  getCards(p,1);
               }


            }
            
           
         }

          for (int j=0;j<p->killers[i]->debuff.size();j++)
          {
             if (p->killers[i]->debuff[j].turnsleft==0)
            {
               p->killers[i]->debuff.erase(p->killers[i]->debuff.begin()+j, p->killers[i]->debuff.begin()+j+1);
               j--;
            }
            else
            {
               if (p->killers[i]->debuff[j].turnsleft>0)
                   p->killers[i]->debuff[j].turnsleft--;

            }

          }



      }


}

void afterTenTurns (Player *p, int turns)
{
   int r[]={50,75,100,150,200,300};
   int num=0;
   if (turns>=16)
      num=300;
   else
      num=r[turns-10];
   
   for (int i=0;i<p->killers.size();i++)
   {
      
      int res=p->killers[i]->current.hp-=num;
      if (p->killers[i]->current.hp<=0)
      {
         p->killers.erase(p->killers.begin()+i, p->killers.begin()+i+1);
         i--;
      }

   }

}


      
