#include <stdio.h>
int main(void)
{int N,K,S,X,Y,Z,k,l,i,m,tmp;
	scanf("%d%d",&K,&S);
	tmp=0;
for(X=0;X<=K;X++){
	if((S-X>=0)&&(S-X<=2*K+1)){
	if(S-X<=K){
	tmp+=S-X+1;}
	else
	tmp+=2*K+X-S+1;}}
	printf("%d",tmp);



	return 0;
}
