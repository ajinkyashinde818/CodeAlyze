#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define print(x) printf("%d",x)
#define scan(x) scanf("%d",&x)
#define printn(x) printf("%d\n",x)
#define rep(i,n,m) for(int i = n; i < m; i++)

int main(void){
	int i,n,x;
	int max = -pow(10,9);
	int min;
	
	
	scan(n);
	rep(i,0,n){
		scan(x);
		
		if(max < x - min && i != 0){
			max = x - min;
		}
		if(i == 0){
			min = x;
		}else if(min > x){
			min = x;
		}
	}
	printn(max);
	return 0;
}
