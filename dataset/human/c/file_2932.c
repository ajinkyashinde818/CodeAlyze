#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793

int main(){
	int k, s;
	int count=0;
	scanf("%d%d", &k, &s);
	for(int y=0; y<=k; y++){
		for(int z=0; z<=k; z++){
			if((y+z>=s-k) && (y+z<=s)){
				count++;
			}
		}
	}
	printf("%d\n", count);

	return 0;
}
