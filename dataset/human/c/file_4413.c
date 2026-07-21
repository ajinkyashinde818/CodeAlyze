#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>


int N_all;


int main(int argc, char* argv[]){
    int i,j;
    int xx,yy,count;
    count=0;
    scanf("%d",&N_all);
    for(i=1;i<=N_all;i++){
        scanf("%d %d",&xx,&yy);
        if( xx == yy ){
            count++;
        }else{
            count = 0;
        }
        if(count >=3){
            printf("Yes");
            break;
        }
    }
    if(count<=2){
        printf("No");
    }
    return 0;
}
