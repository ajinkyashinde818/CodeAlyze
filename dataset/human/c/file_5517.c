#include<stdio.h>
#include<math.h>

int main(){
	int n;
	int a[1000000];
	int b;
	int i, j, p;
	int c[10000][2];
	p = 1;
	while (1==1){
		scanf("%d", &c[p][0]);
		if(c[p][0]!=0)p++;
		else break;
	}
	//p--;
		b = (int)pow(1000000.0, 0.5);
		a[0] = -1;
		for (i = 2; i <= b; i++){
			for (j = 2; j <= 1000000/ i; j++){
				a[i*j - 1] = -1;
			}
		}
	//	printf("%d-%d\n",c[0][0],c[1][0]);
	for (i = 1; i < p; i++){	
		c[i][1] = 0;
		for (j = 1;c[i][0]>0; j++){
			if (a[j - 1] != -1){ 
				c[i][1]+=j; 
				c[i][0]--;
			}
		}
		printf("%d\n", c[i][1]);
	}

	return 0;
}
