#include <stdio.h>
int abs(int n){
		if(n<0){
		return -1*n;}else
		return n;}
int main(void)
{int N,A,M,B,x,i,k,l,m,flag,sum;
	scanf("%d",&N);
	int a[100000];
	int b[100000];
	int c[50];
	int d[50];
	int tmp[50];
	b[0]=1;
	flag=0;
	for(i=0;i<=N-1;i++){
		scanf("%d",&a[i]);}
	
	for(x=0;x<=N-1;x++){
		b[x+1]=a[b[x]-1];}
	for(k=1;k<=N;k++){
		if(b[k]==2){
			flag=1;
			sum=k;
			break;}}
if(flag==1)
printf("%d",k);
else
printf("-1");



	return 0;
}
