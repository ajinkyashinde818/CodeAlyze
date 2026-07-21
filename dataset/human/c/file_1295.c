#include <stdio.h>

const int putterns[8][8]={
	{1,2,1,2,1,4,1,4},
	{1,2,1,4,1,4,1,2},
	{1,4,1,2,1,2,1,4},
	{1,4,1,4,1,2,1,2},
	{2,1,2,1,4,1,4,1},
	{2,1,4,1,4,1,2,1},
	{4,1,2,1,2,1,4,1},
	{4,1,4,1,2,1,2,1}
};

int main(void) {
	int kyaku[8];
	int now,min,mini;
	int i,j;
	while(scanf("%d%d%d%d%d%d%d%d",
			&kyaku[0],&kyaku[1],&kyaku[2],&kyaku[3],
			&kyaku[4],&kyaku[5],&kyaku[6],&kyaku[7])==8) {
		min=0x7fffffff;
		mini=0;
		for(i=0;i<8;i++) {
			now=0;
			for(j=0;j<8;j++) {
				if(kyaku[j]>putterns[i][j]) {
					now+=kyaku[j]-putterns[i][j];
				}
			}
			if(now<min) {
				min=now;
				mini=i;
			}
		}
		printf("%d %d %d %d %d %d %d %d\n",
			putterns[mini][0],putterns[mini][1],
			putterns[mini][2],putterns[mini][3],
			putterns[mini][4],putterns[mini][5],
			putterns[mini][6],putterns[mini][7]);
	}
	return 0;
}
