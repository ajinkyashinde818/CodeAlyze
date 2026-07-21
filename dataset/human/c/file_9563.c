#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
 
 
int main(){
int n;
int d;
int x;
int a[101];
int i,j=1;
int temp=0;
int temp2=0;
scanf("%d",&n);
scanf("%d%d",&d,&x);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
	
}
for(i=0;i<n;i++){
	
	for(j=1;j<=d;j++){
		//printf("!%d\n",a[i]*j+1);
	if(a[i]*j+1<=d){
	temp2++;
	//printf("%d\n",temp2);
	}
	}
	temp2++;
	
	
}
printf("%d\n",temp2+x);
	return 0;
}
