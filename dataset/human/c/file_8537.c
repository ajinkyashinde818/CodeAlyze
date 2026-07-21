#include<stdio.h>
char str[2];
int main(){
	int a;
	scanf("%d",&a);
	long long v=0;
	for(int i=0;i<a;i++){
		int b,c;
		scanf("%d%s%d",&b,str,&c);
		if(str[0]=='(')v+=c;
		else v-=c;
		if(v==0)printf("Yes\n");
		else printf("No\n");
	}
}
