#include<stdio.h>

int main(void){

	int x,y,i,t;
	int a[10000];
	i = 0;
	t = 0;
	y = 0;
	

	while(1){

		scanf("%d",&a[y]);
		
		x = a[y];

		y += 1;

		if(x == 0){

			break;

		}
		

	}

	while(i < y){

		if(a[t] == 0){
			break;
		}

		printf("Case %d: %d\n",t+1,a[t]);
		
		t += 1;
		i += 1;


	}

}
