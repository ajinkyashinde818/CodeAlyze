#include<stdio.h>
#include<stdlib.h>

int main(){
	int* data=(int*)(malloc(sizeof(int)*60000));
	int* head=data-1;
	do{
		head++;
		scanf("%d",head);
	}while(*head!=0);
	head=data;
	while(*head!=0){
		printf("Case %d: %d\n",((int)(head-data))+1,*head);
		head++;
	}
	return 0;
}
