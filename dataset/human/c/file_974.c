#include<stdio.h>
int main(){
	int n,k;
	char a;
	scanf("%d%d",&n,&k);
	if(n==0){
		if(k>1988){
			k=k-1988;
			a='H';
		}
		else if(k>1925){
			k=k-1925;
			a='S';
		}
		else if(k>1911){
			k=k-1911;
			a='T';
		}
		else{
			k=k-1867;
			a='M';
		}
	}
	else{
		if(n==1)k=k+1867;
		else if(n==2)k=k+1911;
		else if(n==3)k=k+1925;
		else k=k+1988;
	}
	if(n==0)printf("%c",a);
	printf("%d\n",k);
	return 0;
}
