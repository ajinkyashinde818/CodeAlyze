#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long int
#define lim 100010
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) ((x)>0?(x):-(x))

int main(void){
	int r,g,b,n;
	scanf("%d%d%d%d",&r,&g,&b,&n);
	int ans=0;
	for(int i=0;i<(n/r+1);i++){
		for(int j=0;j<(n/g+1);j++){
			if((n-i*r-j*g)%b==0 && (n-i*r-j*g)/b>=0){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
