#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
int main()
{   int n,k,s;
    scanf("%d%d%d",&n,&k,&s);
    if(s!=1000000000){
        for(int i=0;i<k;i++){
            printf("%d ",s);
        }
    
    for(int i=k;i<n;i++){
    printf("1000000000 ");}
    }else{
        for(int i=0;i<k;i++){
            
                printf("1000000000 ");
            
        }
        for(int i=k;i<n;i++){
            printf("1 ");
        }
    }
    return 0;
}
