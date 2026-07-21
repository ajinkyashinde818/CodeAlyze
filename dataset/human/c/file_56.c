#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007


int main(){
	int r,g,b,n;
	scanf("%d%d%d%d", &r, &g, &b, &n);
	int count = 0, i=0, j, k, temp;
	while(r*i<=n){
		j=0;
		while(r*i+g*j<=n){
			temp = n - (r*i+g*j);
			if(temp%b == 0){
				k = temp/b;
				//printf("%d %d %d\n", i, j, k);
				count++;
			}
			j++;
		}
		i++;
	}
	
	printf("%d\n", count);
	return 0;
}
