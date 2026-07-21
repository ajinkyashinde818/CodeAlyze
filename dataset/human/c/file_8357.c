#include<stdio.h>
int main(){
int N,K;
char S[11];

scanf("%d",&N);
scanf("%s",S);
scanf("%d",&K);

for(int i=0;i<N;i++){
if(S[i]!=S[K-1]) S[i]='*';
}

printf("%s",S);
return 0;
}
