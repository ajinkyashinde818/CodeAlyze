#include <stdio.h>

int main(void){
    long n;
    long num[200000];
    long i;
    long max = -2000000000;
	long min;

    scanf("%ld", &n);
    for(i=0; i<n; i++){
        scanf("%ld", &num[i]);
    }
    min = num[0];

    for(i=1; i<n; i++){
        if(max < num[i] - min) max = num[i] - min;
        if(num[i] < min) min = num[i];
    }

    printf("%ld\n", max);
	return 0;
}
