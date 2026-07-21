#include<stdio.h>
int main(){
	int i=1,x;
	int dizi[10000]; 
	dizi[0]=1;
	do{
		scanf("%d",&dizi[i]);
		i++;}
	while(dizi[i-1]!=0);
	if(i!=1){
	x=i-2;
	for(i=1;i<=x;i++){
		printf("Case %d: %d\n",i,dizi[i]);}}

	return 0;
}
