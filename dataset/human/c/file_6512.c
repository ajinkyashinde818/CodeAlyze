#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MOD 1000000007
#define MAXE9 1000000000
 
int i, j, k, l;

int main(){
    int max = 0;
    int min = MAXE9;
    int R[200010];
    int n;
    
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &R[i]);
    }

    max = R[1] - R[0];
    min = R[0];
    for(i=1;i<n;i++){
        if(max <= R[i] - min) max = R[i] - min;
        if(min >= R[i]) min = R[i];
    }
    printf("%d\n", max);
    
}
