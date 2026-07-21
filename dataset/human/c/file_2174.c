#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int SIZE=100001;

int main(void){
	char S [SIZE];
	int Q;
	char Qs[200001];
	int sizeQs=0;
	char Qb[200001];
	int sizeQb=0;
	bool X=true;//true 正順

	int T,F;
	char C;
	scanf("%s",S);
	scanf("%d",&Q);
	for(int k=0;k<Q;k++){
		scanf("%d",&T);
		if(X){
			if(T==1){
				X=false;
			}else{
				//T==2
				scanf("%d %c",&F,&C);
				if(F==1){
					Qs[sizeQs]=C;
					sizeQs++;
				}else{
					Qb[sizeQb]=C;
					sizeQb++;
				}
			}
		}else{
			if(T==1){
				X=true;
			}else{
				//T==2
				scanf("%d %c",&F,&C);
				if(F==2){
					Qs[sizeQs]=C;
					sizeQs++;
				}else{
					Qb[sizeQb]=C;
					sizeQb++;
				}
			}
		}
	}
	//出力
	if(X){
		for(int w=0;w<sizeQs;w++)printf("%c",Qs[sizeQs-1-w]);
		printf("%s",S);
		for(int w=0;w<sizeQb;w++)printf("%c",Qb[w]);
	}else{
		for(int w=0;w<sizeQb;w++){
			printf("%c",Qb[sizeQb-1-w]);
			}
		int m=strlen(S);
		for(int w=0;w<m;w++)printf("%c",S[m-w-1]);
		for(int w=0;w<sizeQs;w++)printf("%c",Qs[w]);
	}
}
