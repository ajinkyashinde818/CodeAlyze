#include<stdio.h>
int main(void){
	int n;
	int i;
	int stone,person;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d %d",&stone,&person);
		while(1){
			stone -= person;
			if(stone <= 0){
				break;
			}
		}
		printf("%d\n",stone + person);
	}
	return 0;
}
