#include <stdio.h>

int main(){
int n;
int ctr=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
	int a,b;
	scanf("%d %d",&a,&b);
	if (a == b){
		ctr++;
	}
	else{
		ctr = 0;
	}
	if(ctr==3){
		printf("Yes\n");
		return 0;
	}
}
printf("No");
return 0;
}
