#include<stdio.h>
int main(void)
{
 	int a,s,i,j,k,cnt;
	scanf("%d",&k);
 	scanf("%d",&s);
 	cnt=0;
 	for(i=0;i<=k;i++){
		for(j=0;j<=k;j++){
			if(0<=s-i-j&&s-i-j<=k){
				cnt++;
			}
		}
	}
    printf("%d\n",cnt);
    return 0;
}
