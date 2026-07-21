#include "stdio.h"

int main(void){
int h[500],w[500],i,j,k=0;
scanf("%d%d",&h[0],&w[0]);
while(w[k]||h[k]){
k++;
scanf("%d%d",&h[k],&w[k]);
}
k=0;
while(h[k]||w[k]){
for(j=0;j<h[k];j++){
	for(i=0;i<w[k];i++)
	if((i+j)%2){
	printf(".");
	}
	else{
	printf("#");
	}
	printf("\n");
	}
printf("\n");
k++;
}
return 0;
}
