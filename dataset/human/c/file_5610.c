#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007

int main(){
	long int x;
	scanf("%ld", &x);
	long int point=0;
	long int count=0;
	count = x/11;
	point = count*11;
	count = count*2;
	while(point < x){
		if(count%2 == 0){
			point += 6;
			count++;
		}
		else{
			point += 5;
			count++;
		}
	}

	printf("%ld\n", count);
	
	return 0;
}
