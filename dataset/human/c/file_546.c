#include <stdio.h>

int main(){
	int n,i;
	long long int data[200000]={0},a=0,b=0,t1=0,t2=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%lld",&data[i]);
		b+=data[i];
	}
	
	for(i=0;i<n-1;i++){
		a+=data[i];	
		b-=data[i];
		if(a>b){
			t1=a-b;	
		}else{
			t1=b-a;	
		}
		if(i==0){
			t2=t1;
		}else if(t2>t1){
			t2=t1;	
		}
	}
	
	printf("%lld\n",t2);
	
return 0;
}
