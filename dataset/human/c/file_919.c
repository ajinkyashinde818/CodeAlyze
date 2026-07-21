#include<stdio.h>

int main(){
	int i,j,k,l,n,m;
	int q,w,e,r,t,y;
	int a[100002];

//acwhile(1){
	scanf("%d",&n);
//if(n==0)break;
	for(i = 0;i < 100002;i++)a[i]=0;
	for(i = 0;i < n;i++){
		scanf("%d%d",&q,&w);
		a[q]++;
		a[w+1]--;
	}
	w = 0;
	q = a[0];
	for(i = 1;i < 100002;i++){
		q += a[i];
		if(q+1 >= i)w=i-1;
	}
	printf("%d\n",w);
//}
	return 0;
}
