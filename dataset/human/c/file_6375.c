#include<stdio.h>
#include<limits.h>
int main(){
	int i,n,max=-INT_MAX,min,r[200000];
	scanf("%d",&n);
	if(n<2 || n>200000) return 1;
	for(i=0;i<n;i++){
		scanf("%d",&r[i]);
		}
	min=r[0];
	for(i=1;i<n;i++){
		if(max<r[i]-min) max=r[i]-min;
		if(min>r[i]) min=r[i];
		}
	printf("%d\n",max);	
	return 0;
	}
