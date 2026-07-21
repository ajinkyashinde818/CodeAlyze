#include<stdio.h>

int main(){

    int N,K,cnt=0;

    scanf("%d %d",&N,&K);

    int h[N];

    for(int i=1;i<=N;i++){

        scanf("%d",&h[i]);
    }

    for (int j=1;j<=N;j++){

        if (h[j]>=K) cnt++;
    
    }

    printf("%d",cnt);
 	return 0;


}
