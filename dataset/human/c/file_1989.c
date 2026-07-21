#include<stdio.h>
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	if(a+b>=c-1)printf("%d\n",b+c);
	else printf("%d\n",b+a+b+1);
	return 0;
}
