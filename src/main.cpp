#include <iostream>
//#include "f.hpp"
#include "../include/function.h"
using namespace std;



int main()
{  
   

   Game *game=new Game();
   game->player1=initialOwner();
   game->opponent=initialOpponent();


   vector<Killer*> killerSpeed(6);
   int finishFlag=0;
   cout<<"我方打手位置"<<endl;
   for(int i =0; i<game->player1->killers.size(); i++)
   {
      cout<<" 打手id: " <<game->player1->killers[i]->id <<" location:"<<game->player1->killers[i]->location;
   }
   cout<<endl;
   cout<<"对方打手位置"<<endl;
   for(int i =0; i<game->opponent->killers.size(); i++)
   {
      cout<<" 打手id: " <<game->opponent->killers[i]->id <<" location:"<<game->opponent->killers[i]->location;
   }
   cout<<endl;
    for ( ; ; )
   {
     
      //计算速度
      killerSpeed=CalculateSpeed(game->player1->killers,game->opponent->killers);
      
      //判断有没有失去下一轮目标优先级
      killerSpeed=checkDebuff12(killerSpeed);

      //输出出手顺序
      cout<<"order:"<<endl;
      for (int i=0;i<killerSpeed.size();i++)
      { 
         if ( killerSpeed[i]->id_host==1)
             cout<<"You:"<< killerSpeed[i]->id<<" " ;
         else
             cout<<"Opponent:"<< killerSpeed[i]->id<<" ";
      }
      cout<<endl;


      //我方，敌方发牌
      if (game->turn==0)
      {
         getCards(game->player1,6);
         getCards(game->opponent,6);
      }
      else
      {
         getCards(game->player1,3);
         getCards(game->opponent,3);
      }

     


      //我方可用牌显示并选牌   
      cout<<"Owner display and select cards"<<endl;
      cout<<"Owner energy:"<<game->player1->energy<<endl; 
      for (int i=0;i<game->player1->killers.size();i++)
      {
         cout<<"打手"<<game->player1->killers[i]->id<<":";
         for (int j=0;j<game->player1->killers[i]->cardsCanUse.size();j++)
            cout<<" "<<game->player1->killers[i]->cardsCanUse[j]->id;
         cout<<endl;
      }
      cout<<endl;
      cardChoosen(game->player1);
      


      //敌方可用牌显示并选牌
      cout<<"Opponent display and select cards"<<endl; 
      cout<<"Opponent energy:"<<game->opponent->energy<<endl; 
      for (int i=0;i<game->opponent->killers.size();i++)
      {
         cout<<"打手"<<game->opponent->killers[i]->id<<":";
         for (int j=0;j<game->opponent->killers[i]->cardsCanUse.size();j++)
            cout<<" "<<game->opponent->killers[i]->cardsCanUse[j]->id;
         cout<<endl;
      }
      cout<<endl;
      cardChoosen(game->opponent); 
      
      addShield(game->player1);
     
      addShield(game->opponent);

      //cout<<killerSpeed.size()<<endl;
      //开始战斗
      for (int i=0;i<killerSpeed.size();i++)
      {
         //cout<<i<<endl;
         //每回合恢复20个护盾值
         //if (killerSpeed.size()==0)
         //   break;
         checkBuffCARD109(killerSpeed[i]);
          //我方
         //cout<<"id"<<killerSpeed[i]->id_host<<endl;
          if ( killerSpeed[i]->id_host==1)
         {
            //计算攻击的小精灵
            Killer* to;
            to=checkDebuffGETATTACKFIRST(game->opponent);
            if (to==NULL)
               to=calculatePirority(game->opponent);
            //cout<<to->location<<endl;

            
            
            //cout<<"You killers"<<endl;
            //cout<<"size"<<killerSpeed[i]->cardsToUse.size()<<endl;
            for (int j=0;j<killerSpeed[i]->cardsToUse.size();j++)
            {
               //killerSpeed[i]->cardsToUse[j]->Show();
               //cout<<to<<endl;
               if (to==NULL || game->opponent->killers.size()==0 || game->player1->killers.size()==0)
                  break;
               //cout<<"Size of killers"<<j<<" "<< game->opponent->killers.size()<<game->player1->killers.size()<<endl;
               applycard(killerSpeed[i]->cardsToUse[j], killerSpeed[i], to, game->player1, game->opponent, game->turn, i);
               //cout<<"Success"<<j<<endl; 
              // cout<<"Su"<<endl;
               
              // cout<<"Size of killers"<<j<<" "<<  game->opponent->killers.size()<<game->player1->killers.size()<<endl;

            }
            
           
            //cout<< killerSpeed[i]->shield<<" ";
         }
         else
         {
            //计算攻击的小精灵
            Killer* to;
            to=checkDebuffGETATTACKFIRST(game->player1);
            if (to==NULL)
               to=calculatePirority(game->player1);
            

            //applycard();

           
            //cout<<"Opponent killers"<<endl;
            //cout<<killerSpeed[i]->cardsToUse.size()<<endl;
            //cout<<"size"<<killerSpeed[i]->cardsToUse.size()<<endl;
            for (int j=0;j<killerSpeed[i]->cardsToUse.size();j++)
            {
               //killerSpeed[i]->cardsToUse[j]->Show();
               //cout<<killerSpeed[i]->cardsToUse[j]->id<<endl;
               if (to==NULL || game->player1->killers.size()==0 || game->opponent->killers.size()==0)
                  break;
               //cout<<"Size of killers"<<j<<" "<< game->player1->killers.size()<< game->opponent->killers.size()<<endl;
               applycard(killerSpeed[i]->cardsToUse[j], killerSpeed[i], to, game->opponent, game->player1, game->turn, i);
               //cout<<"Su"<<endl;
               //cout<<"Success"<<j<<endl; 
            
               //cout<<"Size of killers"<<j<<" "<<  game->player1->killers.size()<<game->opponent->killers.size()<<endl;
            
            }
            //cout<<"Success"<<endl;
            

         }
         //cout<<"s"<<endl;
         if (judgeFinish(game->player1,game->opponent))
         {
            finishFlag=1;
            cout<<game->turn<<endl;
            cout<<"Finish game"<<endl;
            break;
         }

      }
      if (finishFlag==1)
         break;
     
      for (int i=0;i<killerSpeed.size();i++)
      {
         killerSpeed[i]->Show();
      }

      // 将使用过的卡牌放入弃卡堆，并清空使用卡牌容器
      cardsRejectandClean(game->player1);
      cardsRejectandClean(game->opponent);
      // 每回合只能触发一次 或者最后判断的状态

      lastJudgeDebuffandBuff (game->player1);
      lastJudgeDebuffandBuff (game->opponent);
      

      //下一回合
      reduceTurnBuffandDebuff(game->player1);
      reduceTurnBuffandDebuff(game->opponent);
      game->turn++;
      
      if(game->turn>=10)
      {  
         afterTenTurns (game->player1, game->turn);
         afterTenTurns (game->opponent, game->turn);
         
         if (judgeFinish(game->player1,game->opponent))
         {
            finishFlag=1;
            cout<<game->turn<<endl;
            cout<<"Finish game"<<endl;
            break;
         }
      }
      
      addEnergy(game->player1,2);
      addEnergy(game->opponent,2);
    
      cout<<endl;

      
         

   }

   
} 