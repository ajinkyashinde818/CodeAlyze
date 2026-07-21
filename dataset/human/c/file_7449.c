#include <stdio.h>


int main(void) {

	// 1_3-A Print Many Hello World

	int i,nums = 0;
	int inum;
	int num[10000];

	for(i=0; i<10000; i++){
		scanf("%d",&inum);
		if(inum == 0){
			break;
		}
		num[i] = inum; 
		nums++;
	}
	for(i=0;i<nums;i++){
		printf("Case %d: %d\n",i+1,num[i]);
	}
        return 0;
}
