#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void){
    int n;
    int a,b;
    int yes=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        if(a==b){yes++;}
        else{yes=0;}
        if(yes>=3){printf("Yes\n");return 0;}
    }
    printf("No\n");

}
