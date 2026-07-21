#include <stdio.h>

int main(void) {
	int num;
	int count;
	while(1) {
		scanf("%d",&num);
		if(num==0)break;
		for(count=0;num>1;count++)num=num%2?num*3+1:num/2;
		printf("%d\n",count);
	}
	return 0;
}
