#include<stdio.h>
int main(){

	int data[10000];

	int i = 1,n;

	while(1){

		scanf("%d",&data[i-1]);

		if(data[i-1] == 0){
			break;
		}

		i++;
	}

	for (n = 1;n < i; n++)
	{
		printf("Case %d: %d\n",n,data[n-1] );
	}



return 0;
}
