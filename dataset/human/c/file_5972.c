#include<stdio.h>
int max(int a,int b);
int min(int a,int b);
int main(void){
	int a[200000],m,i,maxv;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	maxv=-2000000000;
	int minv=a[0];
	for(i=1;i<m;i++){
		maxv=max(maxv,a[i]-minv);
		minv=min(minv,a[i]);
	}
	printf("%d\n",maxv);
	return 0;
}
int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}
