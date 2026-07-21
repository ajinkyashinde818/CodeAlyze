#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#define ll long long
#define mod 1000000007
int main(){
    int i,j,n,flag=0,d[112][2]={{}};
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d %d",&d[i][0],&d[i][1]);
        if(d[i][0]==d[i][1])flag++;
        else flag=0;
        if(flag==3){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}
