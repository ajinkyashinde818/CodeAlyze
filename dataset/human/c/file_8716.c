#include<stdio.h>
#include<string.h>

int main(){
int n;
int a[100000];
int i;
int c;
int b;
int x=0;
scanf("%d",&n);
for(i=0;i<n;i++){
	
	scanf("%d",&a[i]);
	
}
c=1;
b=a[0];
x++;
do{
	c=a[c-1];
	
	
	
	x++;
	
	
	if(x>n){
		
		break;
	}
	
	
	
	
	
	
	}while(c!=2);


	if(x>n){
		
		printf("-1\n");
	}else{
	printf("%d\n",x-1);
	}
	
	

	return 0;
}
