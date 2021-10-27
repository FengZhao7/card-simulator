#ifndef BUFF_H
#define BUFF_H
#include <iostream>
using namespace std;
enum property{SPEED, MORAL, ATTACK, GETATTACKFIRST, NOLASTTURN, CANTATTACK, SHIELDDAMAGEDOUBLE, CANTCRITIC,
GETDOUBLEDAMAGE, LOSETWOHP, NOSHIELD1, LOSEPRIORITY, NOSHIELD2, CARD4, CARD7, CARD8, CARD9, CARD13, BANPART,
CARD20, CARD37, CARD38, CARD65, CARD73, CARD106,CARD109, CARD112, CARD113, CARD125, NOTREAT,CARD19, CARD133,
CANTCLOSECOMBAINT};
//Debuff:  1. GETATTACKFIRST  2. ATTACK  3. NOLASTTURN (lastturn function) 4. CANTATTACK 5. SHIELDDAMAGEDOUBLE 6. CANTCRITIC 7. GETDOUBLEDAMAGE 8. MORAL 
//         9. LOSETWOHP 10. NOSHIELD1 11.  SPEED 12. LOSEPRIORITY 13. NOSHIELD2 (no)

// end: CARD4 CARD9
// dealDamage: CARD7, CARD8, CARD13, BANPART (card16 card55), CARD20, CARD37, CARD38 (card 76), CARD65(debuff), CARD73
// first: GETATTACKFIRST, CARD109
class Buff{
    public:
    property type;
    int turnsleft;
    unsigned int part;
    

    void Show()
    {
        cout << "type " << type << " turns left"  << turnsleft <<endl;
    }
    

};



class Debuff{
    public:
    property type;
    int turnsleft;
    unsigned int part;
    void Show()
    {
        cout << "type " << type << " turns left"  << turnsleft <<endl;
    }
};



#endif


