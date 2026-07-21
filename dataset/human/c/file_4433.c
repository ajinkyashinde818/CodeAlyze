#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007
//#define DEBUG

long long int combination(long long int n, long long int r)
{
	//printf("n:%lld, r:%lld\n", n, r);
    if (r == 0 || r == n)
        return (1);
    else if (r == 1)
        return (n);
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

//qsort用、昇順
int compare_int(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
//qsort(array, 10, sizeof(int), compare_int)



int main(){
	int n, hantei[120];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int small, large;
		scanf("%d%d", &small, &large);
		if(small == large) hantei[i] = 1;
		else hantei[i] = 0;
	}

	int p = 0, f=0;
	for(int i=0; i<n; i++){
		if(hantei[i] == 1) p++;
		else p = 0;
		if(p >= 3){
			f = 1;
			break;
		}
	}
	
	if(f == 1) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}
