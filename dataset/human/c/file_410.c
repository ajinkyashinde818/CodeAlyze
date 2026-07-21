#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007


//qsort用、昇順
int compare_int(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}


int main(){
	int n, r;
	scanf("%d%d", &n, &r);
	if(n>=10) printf("%d\n", r);
	else{
		r += 100*(10-n);
		printf("%d\n", r);
	}
	//printf("%d\n", ans);
	
	return 0;
}
