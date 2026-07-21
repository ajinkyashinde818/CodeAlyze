#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n==m){
        printf("Yes");
        return 0;
    }
    printf("No");
    return 0;
}
