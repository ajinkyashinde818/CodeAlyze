#include <stdio.h>
 


long long int minx(long long int v[],int n){
	int i,j,k;
	long long int tmp;
	tmp=v[0];
	for(i=1;i<=n-1;i++){
		if(tmp>v[i])
		tmp=v[i];}
		return tmp;}
int maxx(int v[],int n){
	int i,j,k,tmp;
	tmp=v[0];
	for(i=1;i<=n-1;i++){
		if(tmp<v[i])
		tmp=v[i];}
		return tmp;}
int max(int n1,int n2,int n3){
	int tmp;
	tmp=n1;
	if(n2>tmp)
	tmp=n2;
	if(n3>tmp)
	tmp=n3;
	return tmp;}
int max2(int n1,int n2){
	int tmp;
	tmp=n1;
	if(n2>tmp)
	tmp=n2;
	return tmp;}
int min3(int n1,int n2,int n3){
	int tmp;
	tmp=n1;
	if(n2<tmp)
	tmp=n2;
	if(n3<tmp)
	tmp=n3;
	return tmp;}
int min2(int n1,int n2){
	int tmp;
	tmp=n1;
	if(n2<tmp)
	tmp=n2;
	return tmp;}
long long int abs(long long int n){
	if(n>=0)
	return n;
	else return(-1)*n;
}
int main(void)
{int N,A,M,B,j,i,k,H,W,l,m,flag;
	long long int sum,min;
	scanf("%d",&N);
	long long int a[200000];
	long long int x[200000];
	long long int diff[200000];
	flag=0;
	sum=0;
	for(i=0;i<=N-1;i++){
		scanf("%lld",&a[i]);}
	x[0]=a[0];
	for(j=0;j<=N-1;j++){
		sum+=a[j];}
	for(l=0;l<=N-2;l++){
			x[l+1]=x[l]+a[l+1];
			diff[l]=abs(sum-2*x[l]);}
	printf("%lld",minx(diff,N-1));



	return 0;
}
