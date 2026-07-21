#include <stdio.h>

void addtosyoutai(int*,int*,int,int,int);

int main(void) {
	int ninsuu;
	int friends[500*500];
	int listlength;
	int syoutai[500];
	int tomodatia;
	int tomodatib;
	int i;
	int ii;
	int syoutaininsuu;
	while(1) {
		scanf("%d",&ninsuu);
		scanf("%d",&listlength);
		if(ninsuu==0 && listlength==0)break;
		for(i=0;i<ninsuu;i++) {
			for(ii=0;ii<ninsuu;ii++) {
				friends[i*500+ii]=0;
			}
			syoutai[i]=0;
		}
		for(i=0;i<listlength;i++) {
			scanf("%d %d",&tomodatia,&tomodatib);
			friends[(tomodatia-1)*500+(tomodatib-1)]=1;
			friends[(tomodatib-1)*500+(tomodatia-1)]=1;
		}
		addtosyoutai(friends,syoutai,0,ninsuu,1);
		syoutaininsuu=0;
		for(i=1;i<ninsuu;i++) {
			if(syoutai[i])syoutaininsuu++;
		}
		printf("%d\n",syoutaininsuu);
	}
	return 0;
}

void addtosyoutai(int friends[],int syoutai[],int you,int ninsuu,int gonext) {
	 int i;
	 for(i=0;i<ninsuu;i++) {
		 if(friends[you*500+i]) {
			 syoutai[i]=1;
			 if(gonext)addtosyoutai(friends,syoutai,i,ninsuu,0);
		 }
	 }
}
