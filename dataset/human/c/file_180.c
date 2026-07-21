#include <stdio.h>

const int syousuu_table[7]={
	78125,156250,312500,625000,1250000,2500000,5000000
};

int main(void) {
	int Q,nowquery;
	unsigned int s;
	int fugou,seisuu,syousuu;
	int i,syousuu2;
	scanf("%d",&Q);
	for(nowquery=0;nowquery<Q;nowquery++) {
		scanf("%x",&s);
		fugou=s>>31;
		seisuu=(s>>7)&0xFFFFFF;
		syousuu=s&0x7F;
		for(i=syousuu2=0;i<7;i++) {
			if((syousuu>>i)&1)syousuu2+=syousuu_table[i];
		}
		
		if(fugou)putchar('-');
		printf("%d.",seisuu);
		if(syousuu2==0)puts("0");
		else {
			for(;syousuu2<1000000;syousuu2*=10)putchar('0');
			while(syousuu2%10==0 && syousuu2>0)syousuu2/=10;
			printf("%d\n",syousuu2);
		}
	}
	return 0;
}
