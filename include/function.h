#ifndef FUNCTION_H
#define FUNCTION_H

#include "killer.h"
//buff.C++
// 
void applyBuff(Killer *killer, Buff buff);
void removeAllBuff(Killer *killer);
void removeDebuff(Killer *killer);
void applyDeBuff(Killer *killer, Debuff debuff);
vector<Killer*> checkDebuff12(vector<Killer*> killer);
void removeAllDebuff(Killer *killer);

void checkBuffCard7 (Killer *from, Killer *to);
void checkBuffCard8 (Killer *from, Killer *to, Player *opp);
void checkBuffCard13 (Card *card, Killer *to, Player *opp);
void checkBuffCARD38  (Killer *to);
void checkDebuffCARD65  (Killer *to);
void checkBuffCARD109(Killer *own);
void checkDebuff9(Killer *k);
void checkBuffCARD133 (Killer *from, Killer *to);

bool checkDebuffCANTCLOSECOMBAINT(Card *card, Killer *from);
bool checkBuffCARD19( Card *card, Killer *to);
bool checkBuffCard106 (Killer *to);
bool checkBuffCard112 (Killer *to);
bool checkBuffCard113 (Killer *to);
bool checkBuffCard125(Killer *to);



bool checkBuffBANPART (Card *card, Killer *to);
bool checkBuffCARD20 (Card *card, Killer *to, Player *opp);
bool checkBuffCARD37 (Card *card, Killer *from, Player *own);
bool checkBuffCARD73 (Killer *to);
//bool checkDebuffNOTREAT(Killer *own);
bool checkDebuffBool(Killer *k, property p);
bool checkDebuffBoolNext(Killer *k, property p);

Killer *checkDebuffGETATTACKFIRST( Player *opp );

void reduceTurnBuffandDebuff(Player *p);

// player.cpp
// 我方和对手的初始化函数，可以更改参数设置不同的killer
Player *initialOwner();
Player *initialOpponent();

//Card.CPP
vector<Card*> initCardforKiller(int c[4],int id_host);
void fillCardInfo(Card *card);


vector<Card*> initCardStack(vector<Killer*> &killer);
float cardBonus(Killer *killer, Card *card, float ratio);

//killer.cpp
bool compareSpeed(const Killer* a, const  Killer* b);
float classBonus(Killer& from, Killer& to, float ratio);
Killer *initKiller(char cls, unsigned int id, unsigned int id_host, unsigned int hp, unsigned int speed, unsigned int moral, unsigned int skill, int c[4],int loc);
vector<Killer*>  CalculateSpeed (vector<Killer*> &killer_owner, vector<Killer*> &killer_opp);
float calculateCriticChance(Killer *killer);
int dealDamage(Killer *from, Killer *to, float ratio, Card *card, float extraDamage, float extraCreticDamage, Player* killerOwner, Player* otherplayer, float creticRate);
float lastTurnChance(Killer *killer);
int calculateBonusDmg(Killer *killer, Card *card);
void addShield(Player *player);

//fight.cpp
void getCards (Player *owner,int num);
void cardChoosen(Player *player);
bool judgeFinish(Player *owner, Player *opp);
bool comparePirority(const Killer* a, const  Killer* b);
Killer* calculatePirority(Player *opp);
void killerDead(Player *p, Killer *deadKiller);

void cardsRejectandClean(Player *p);

void lastJudgeDebuffandBuff (Player *p);

void afterTenTurns (Player *p, int turns);

//skill.cpp
void applycard(Card* card, Killer* from, Killer* to, Player* killerOwner, Player* otherplayer, int turn, int order);
void Treat(int num, Killer *A);
void addEnergy(Player *p, int num);
bool link(Player *p, char cls, Killer *killer);
bool linkSameCard(Player *p, Killer *killer, Card *card);

bool checkCard(char cls, vector<Card*> card );
bool checkCardSame(Card *card, vector<Card*> card_vector );
bool checkCardSameCls(Card *card, vector<Card*> card_vector );
bool checkCardTwoDifferent(Card *card, vector<Card*> card_vector );
//bool checkLastFight(vector<Killer*> killer1, vector<Killer*> killer2, Killer *own);

Killer *chooseFrontFriend (Killer *own, vector<Killer*> killer );
Killer *findKillerLocation(int l, vector<Killer*> killer );
Killer *findKillerCls(char c, vector<Killer*> killer );
Killer *findKillerNoStatus(killerStatus s, vector<Killer*> killer );
Killer *findKillerFree( vector<Killer*> killer );

Killer *findKillerInjured(vector<Killer*> killer );
Killer *findKillerLeastShield(vector<Killer*> killer );
Killer *findKillerFast( vector<Killer*> killer );

bool compareLocation(const Killer* a, const  Killer* b);
Killer *findKillerDistance( vector<Killer*> killer ,int num);

void treatFirstRow(vector<Killer*> killer, int num);
void throwCards(Player *p);

void cleanDeadKiller(vector<Killer*> killer);
#endif