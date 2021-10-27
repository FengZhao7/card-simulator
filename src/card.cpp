#include "../include/function.h"
#include <algorithm>
#include <random> // std::default_random_engine  
#include <chrono> // std::chrono::system_clock
void fillCardInfo(Card *card)
{
    switch (card->id)
    {
    	 case 3:
 		 card->cls='A';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=30;
 		 card->shield=50;
		 card->range = 0;
		 break;
	 case 4:
 		 card->cls='A';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=40;
		card->range = 0;
		 break;
	 case 5:
 		 card->cls='A';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=20;
		  card->range = 0;
		 break;
	 case 6:
 		 card->cls='A';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=0;
 		 card->shield=40;
		 card->range = 2;
		 break;
	 case 7:
 		 card->cls='A';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=30;
 		 card->shield=20;
		 card->range =1;
		 break;
	 case 8:
 		 card->cls='A';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=60;
 		 card->shield=90;
		 card->range=1;
		 break;
	 case 9:
 		 card->cls='A';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=0;
 		 card->shield=120;
		 card->range=2;
		 break;
	 case 10:
 		 card->cls='A';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=105;
 		 card->shield=40;
		 card->range=0;
		 break;
	 case 11:
 		 card->cls='A';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=50;
 		 card->shield=50;
		 card->range =0; 
		 break;
	 case 12:
 		 card->cls='A';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=60;
 		 card->shield=60;
		 card->range=0;
		 break;
	 case 13:
 		 card->cls='A';
 		 card->part=4;
		 card->energy=0;
 		 card->dmg=20;
 		 card->shield=30;
		 card->range=0;
		 break;
	 case 14:
		card->cls='A';
		card->part=3;
		card->energy=1;
		card->dmg=0;
		card->shield=40;
		card->range=2;
		 break;
	 case 15:
 		 card->cls='A';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=70;
		card->range =0;
		 break;
	 case 16:
 		 card->cls='A';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=90;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 17:
 		 card->cls='A';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=0;
 		 card->shield=50;
		 card->range=2;
		 break;
	 case 18:
 		 card->cls='A';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=0;
 		 card->shield=50;
		card->range = 2;
		 break;
	 case 19:
 		 card->cls='A';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=60;
 		 card->shield=80;
		  card->range = 0;
		 break;
	 case 20:
 		 card->cls='A';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=70;
 		 card->shield=80;
		  card->range = 0;
		 break;
	 case 21:
 		 card->cls='A';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=60;
 		 card->shield=80;
		 card->range=1;
		 break;
	 case 22:
 		 card->cls='A';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=30;
 		 card->shield=30;
		 card->range=1;
		 break;
	 case 23:
 		 card->cls='A';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=0;
 		 card->shield=0;
		 card->range=2;
		 break;
	 case 24:
 		 card->cls='A';
 		 card->part=1;
		 card->energy=2;
 		 card->dmg=0;
 		 card->shield=0;
		  card->range=2;
		 break;
	 case 25:
 		 card->cls='B';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=75;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 26:
 		 card->cls='B';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=105;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 27:
 		 card->cls='B';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=125;
 		 card->shield=25;
		  card->range = 1;
		 break;
	 case 28:
 		 card->cls='B';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=70;
 		 card->shield=20;
		  card->range=0;
		 break;
	 case 29:
 		 card->cls='B';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=30;
		  card->range=1;
		 break;
	 case 30:
 		 card->cls='B';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=40;
		  card->range=1;
		 break;
	 case 31:
 		 card->cls='B';
 		 card->part=4;
		 card->energy=0;
 		 card->dmg=0;
 		 card->shield=0;
		  card->range=2;
		 break;
	 case 32:
 		 card->cls='B';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=105;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 33:
 		 card->cls='B';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=125;
 		 card->shield=25;
		  card->range = 0;
		 break;
	 case 34:
 		 card->cls='B';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		card->range =0;
		 break;
	 case 35:
 		 card->cls='B';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=130;
 		 card->shield=20;
		  card->range=0;
		 break;
	 case 36:
 		 card->cls='B';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=115;
 		 card->shield=35;
		  card->range=0;
		 break;
	 case 37:
 		 card->cls='B';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=20;
		  card->range=0;
		 break;
	 case 38:
 		 card->cls='B';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 39:
 		 card->cls='B';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 40:
 		 card->cls='B';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=90;
 		 card->shield=20;
		  card->range=0;
		 break;
	 case 41:
 		 card->cls='B';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=50;
 		 card->shield=100;
		  card->range=0;
		 break;
	 case 42:
 		 card->cls='B';
 		 card->part=2;
		 card->energy=0;
 		 card->dmg=0;
 		 card->shield=30;
		  card->range=2;
		 break;
	 case 43:
 		 card->cls='B';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=65;
 		 card->shield=85;
		  card->range=0;
		 break;
	 case 44:
 		 card->cls='B';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=40;
 		 card->shield=20;
		  card->range=0;
		 break;
	 case 45:
 		 card->cls='B';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=35;
 		 card->shield=20;
		  card->range=1;
		 break;
	 case 46:
 		 card->cls='B';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=50;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 47:
 		 card->cls='C';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=160;
 		 card->shield=10;
		  card->range = 1;
		 break;
	 case 48:
 		 card->cls='C';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 49:
 		 card->cls='C';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=0;
		  card->range=1;
		 break;
	 case 50:
 		 card->cls='C';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 51:
 		 card->cls='C';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=30;
		  card->range=1;
		 break;
	 case 52:
 		 card->cls='C';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 53:
 		 card->cls='C';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=20;
		  card->range=1;
		 break;
	 case 54:
 		 card->cls='C';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=25;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 55:
 		 card->cls='C';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=130;
 		 card->shield=0;
		  card->range=1;
		 break;
	 case 56:
 		 card->cls='C';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=20;
		  card->range=1;
		 break;
	 case 57:
 		 card->cls='C';
 		 card->part=4;
		 card->energy=0;
 		 card->dmg=140;
 		 card->shield=0;
		  card->range=1;
		 break;
	 case 58:
 		 card->cls='C';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=10;
		  card->range=1;
		 break;
	 case 59:
 		 card->cls='C';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=140;
 		 card->shield=10;
		  card->range=0;
		 break;
	 case 60:
 		 card->cls='C';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 61:
 		 card->cls='C';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=30;
		  card->range=1;
		 break;
	 case 62:
 		 card->cls='C';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=40;
 		 card->shield=90;
		  card->range=0;
		 break;
	 case 63:
 		 card->cls='C';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=40;
 		 card->shield=10;
		  card->range=1;
		 break;
	 case 64:
 		 card->cls='C';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=50;
 		 card->shield=10;
		  card->range=1;
		 break;
	 case 65:
 		 card->cls='C';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=40;
 		 card->shield=0;
		  card->range=1;
		 break;
	 case 66:
 		 card->cls='C';
 		 card->part=1;
		 card->energy=0;
 		 card->dmg=0;
 		 card->shield=40;
		  card->range=2;
		 break;
	 case 67:
 		 card->cls='C';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 68:
 		 card->cls='C';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=50;
 		 card->shield=0;
		  card->range=1;
		 break;
	 case 69:
 		 card->cls='D';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 70:
 		 card->cls='D';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=130;
 		 card->shield=20;
		 card->range=0;
		 break;
	 case 71:
 		 card->cls='D';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 72:
 		 card->cls='D';
 		 card->part=4;
		 card->energy=0;
 		 card->dmg=30;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 73:
 		 card->cls='D';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=0;
 		 card->shield=100;
		  card->range=2;
		 break;
	 case 74:
 		 card->cls='D';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=130;
 		 card->shield=20;
		  card->range=1;
		 break;
	 case 75:
 		 card->cls='D';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range=1;
		 break;
	 case 76:
 		 card->cls='D';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range = 0;
		 break;
	 case 77:
 		 card->cls='D';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range = 1;
		 break;
	 case 78:
 		 card->cls='D';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=30;
		  card->range = 1;
		 break;
	 case 79:
 		 card->cls='D';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 80:
 		 card->cls='D';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=60;
 		 card->shield=90;
		  card->range=0;
		 break;
	 case 81:
 		 card->cls='D';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 82:
 		 card->cls='D';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=40;
		  card->range=1;
		 break;
	 case 83:
 		 card->cls='D';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 84:
 		 card->cls='D';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=20;
		  card->range=0;
		 break;
	 case 85:
 		 card->cls='D';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=50;
 		 card->shield=80;
		  card->range=0;
		 break;
	 case 86:
 		 card->cls='D';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=70;
 		 card->shield=10;
		  card->range=0;
		 break;
	 case 87:
 		 card->cls='D';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=30;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 88:
 		 card->cls='D';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=70;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 89:
 		 card->cls='D';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 90:
 		 card->cls='D';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=115;
 		 card->shield=35;
		  card->range=0;
		 break;
	 case 91:
 		 card->cls='E';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=90;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 92:
 		 card->cls='E';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=10;
 		 card->shield=130;
		  card->range=0;
		 break;
	 case 93:
 		 card->cls='E';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 94:
 		 card->cls='E';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 95:
 		 card->cls='E';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=20;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 96:
 		 card->cls='E';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=90;
 		 card->shield=60;
		  card->range=0;
		 break;
	 case 97:
 		 card->cls='E';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=70;
		  card->range=0;
		 break;
	 case 98:
 		 card->cls='E';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=1;
		 break;
	 case 99:
 		 card->cls='E';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 100:
 		 card->cls='E';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=50;
		  card->range=1;
		 break;
	 case 101:
 		 card->cls='E';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 102:
 		 card->cls='E';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=20;
 		 card->shield=30;
		  card->range=1;
		 break;
	 case 103:
 		 card->cls='E';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=60;
		  card->range=1;
		 break;
	 case 104:
 		 card->cls='E';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=90;
 		 card->shield=60;
		  card->range=1;
		 break;
	 case 105:
 		 card->cls='E';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=20;
 		 card->shield=80;
		  card->range=0;
		 break;
	 case 106:
 		 card->cls='E';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 107:
 		 card->cls='E';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 108:
 		 card->cls='E';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=40;
 		 card->shield=60;
		  card->range=1;
		 break;
	 case 109:
 		 card->cls='E';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=20;
		  card->range=0;
		 break;
	 case 110:
 		 card->cls='E';
 		 card->part=4;
		 card->energy=0;
 		 card->dmg=10;
 		 card->shield=20;
		  card->range=1;
		 break;
	 case 111:
 		 card->cls='E';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=30;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 112:
 		 card->cls='E';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=70;
 		 card->shield=10;
		  card->range=1;
		 break;
	 case 113:
 		 card->cls='F';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=40;
 		 card->shield=60;
		  card->range=0;
		 break;
	 case 114:
 		 card->cls='F';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=90;
 		 card->shield=60;
		  card->range=1;
		 break;
	 case 115:
 		 card->cls='F';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 116:
 		 card->cls='F';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=60;
		  card->range=0;
		 break;
	 case 117:
 		 card->cls='F';
 		 card->part=1;
		 card->energy=0;
 		 card->dmg=20;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 118:
 		 card->cls='F';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 119:
 		 card->cls='F';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=110;
 		 card->shield=50;
		  card->range=0;
		 break;
	 case 120:
 		 card->cls='F';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=40;
		  card->range=1;
		 break;
	 case 121:
 		 card->cls='F';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=50;
		  card->range=1;
		 break;
	 case 122:
 		 card->cls='F';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=90;
 		 card->shield=50;
		  card->range=1;
		 break;
	 case 123:
 		 card->cls='F';
 		 card->part=3;
		 card->energy=1;
 		 card->dmg=100;
 		 card->shield=40;
		  card->range=1;
		 break;
	 case 124:
 		 card->cls='F';
 		 card->part=1;
		 card->energy=1;
 		 card->dmg=80;
 		 card->shield=50;
		  card->range=1;
		 break;
	 case 125:
 		 card->cls='F';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=60;
 		 card->shield=70;
		  card->range=0;
		 break;
	 case 126:
 		 card->cls='F';
 		 card->part=2;
		 card->energy=1;
 		 card->dmg=120;
 		 card->shield=30;
		  card->range=0;
		 break;
	 case 127:
 		 card->cls='F';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=20;
 		 card->shield=0;
		  card->range=1;
		 break;
	 case 128:
 		 card->cls='F';
 		 card->part=3;
		 card->energy=0;
 		 card->dmg=30;
 		 card->shield=10;
		  card->range=0;
		 break;
	 case 129:
 		 card->cls='F';
 		 card->part=4;
		 card->energy=0;
 		 card->dmg=60;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 130:
 		 card->cls='F';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=30;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 131:
 		 card->cls='F';
 		 card->part=2;
		 card->energy=0;
 		 card->dmg=30;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 132:
 		 card->cls='F';
 		 card->part=1;
		 card->energy=0;
 		 card->dmg=40;
 		 card->shield=0;
		  card->range=0;
		 break;
	 case 133:
 		 card->cls='F';
 		 card->part=4;
		 card->energy=1;
 		 card->dmg=30;
 		 card->shield=40;
		  card->range=0;
		 break;
	 case 134:
 		 card->cls='F';
 		 card->part=4;
		 card->energy=0;
 		 card->dmg=30;
 		 card->shield=0;
		  card->range=1;
		 break;
    default:
        break;
    }
}

vector<Card*> initCardforKiller(int c[4],int id_host)
{
    vector<Card*> res;

    for (int i=0;i<4;i++)
    {
        Card* card=new Card();
        card->id=c[i];
		card->id_host=id_host;
        fillCardInfo( card);
        res.push_back(card);
    }

    return res;
}




vector<Card*> initCardStack(vector<Killer*> &killer)
{
    
     vector<Card*> res(0);
   
      for (int i=0;i<3;i++)
     {
         for (int j=0;j<4;j++)
         {
			 Card *c=new Card(*killer[i]->cards[j]);
             res.push_back(killer[i]->cards[j]);
             res.push_back(c);
         }
     }

	 unsigned seed = chrono::system_clock::now ().time_since_epoch ().count ();  
     shuffle (res.begin (), res.end (), default_random_engine (seed)); 
	 for (int i=0;i<50;i++)
	 {
		 swap(res[rand()%res.size()],res[rand()%res.size()]);
	 }
	 
     //random_shuffle(res.begin (), res.end ());
	
	  
     return res;
}

float cardBonus(Killer *killer, Card *card, float ratio)
{
    if (killer->cls == card->cls)
    {
        ratio = ratio + 0.15;
    }
    else
    {
        if ((killer->cls == 'G') && (card->cls == 'A' || card->cls =='E'))
        {
            ratio = ratio + 0.075;
        }
        else if ((killer->cls == 'H') && (card->cls == 'D' || card->cls =='C'))
        {
            ratio = ratio + 0.075;
        }
        else if ((killer->cls == 'I') && (card->cls == 'B' || card->cls =='F'))
        {
            ratio = ratio + 0.075;
        }
    }
    return ratio;
}


