#include<stdio.h>
int dat[100];
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		int max=1500000;
		int min=1;
		for(int i=0;i<b;i++)scanf("%d",dat+i);
		for(int i=0;i<b;i++)if(min<dat[i])min=dat[i];
		int res=0;
		int at=1;
		while(max-min>1){
			int M=(max+min)/2;
			res=0;
			at=1;
			for(int i=0;i<b;i++){
				if(res+dat[i]<=M)res+=dat[i];
				else{
					at++;
					res=dat[i];
				}
			}
			if(at<=a)max=M;
			else min=M;
		}
		int M=min;
		res=0;
		at=1;
		for(int i=0;i<b;i++){
			if(res+dat[i]<=M)res+=dat[i];
			else{
				at++;
				res=dat[i];
			}
		}
		if(at<=a)printf("%d\n",M);
		else printf("%d\n",max);
	}
}
