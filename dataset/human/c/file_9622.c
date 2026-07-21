#include<stdio.h>
#include<string.h>
struct _data{
	char hit[10];
	int money;
}typedef _data;
_data d[105];
int isHit(char hit[],int n){
	int i;
	for(i=7;i>=0;i--){
		if(d[n].hit[i]=='*')break;
		else if(d[n].hit[i]!=hit[i])return 0;
	}
	return 1;
}
int main(){
	int n,m,i,j,money,sum;
	char hit[10],num[10];
	for(;scanf("%d %d",&n,&m)&&(n||m);){
		sum=0;
		for(i=0;i<n;i++){
			scanf("%s %d",hit,&money);
			strcpy(d[i].hit,hit);
			d[i].money=money;
		}
		for(i=0;i<m;i++){
			scanf("%s",num);
			for(j=0;j<n;j++){
				if(isHit(num,j))sum+=d[j].money;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
