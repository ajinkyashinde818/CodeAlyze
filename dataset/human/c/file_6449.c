#include<stdio.h>
#include<limits.h>
int main(void){
	int n,m = INT_MIN,s,i ;
	scanf("%d",&n);
	
	int a[n];
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	s = a[0];
	for(i = 1;i < n;i++){
		if(m <=a[i]-s){
			m = a[i]-s;
		}
		if(s>a[i]){
			s = a[i];
		}
	}
	printf("%d\n",m);
	
}
