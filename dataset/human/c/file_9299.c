#include<stdio.h>
 int N,K,i;
 int j=0;
 int hoge[100000];
 
 main(void)
{scanf("%d",&N);
 scanf("%d",&K);
 for(i=1;i<=N;i++){
 scanf("%d",&hoge[i-1]);
 
  if(K<=hoge[i-1]){
		j++;
	}
 }
 
printf("%d",j);
}
