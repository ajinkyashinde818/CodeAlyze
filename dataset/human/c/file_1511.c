#include <stdio.h>

int main(void){
	char x[2];
	int n[2],i;
	scanf("%c %c",&x[0],&x[1]);
	for(i=0;i<=1;i++){
		if(x[i]=='A')n[i]=10;
		else if(x[i]=='B')n[i]=11;
		else if(x[i]=='C')n[i]=12;
		else if(x[i]=='D')n[i]=13;
		else if(x[i]=='E')n[i]=14;
		else if(x[i]=='F')n[i]=15;
	}
	if(n[0]<n[1])printf("<\n");
	else if(n[0]==n[1])printf("=\n");
	else if(n[0]>n[1])printf(">\n");
	return 0;
}
