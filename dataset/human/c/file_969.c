#include <stdio.h>
int main(void) {
int E,Y,BASE;
BASE=1867;
scanf("%d %d",&E,&Y);
switch(E){
case 4:BASE+=63;
case 3:BASE+=14;
case 2:BASE+=44;
case 1:printf("%d\n",BASE+Y);
return 0;}
if(Y<=1911){printf("M%d\n",Y-BASE);}
else if(Y<=1925){printf("T%d\n",Y-1911);}
else if(Y<=1988){printf("S%d\n",Y-1925);}
else {printf("H%d\n",Y-1988);}
return 0;
}
