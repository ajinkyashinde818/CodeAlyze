#include<stdio.h>
#define N 1000000000
int main()
{
    long n,k,s;
    long i;
    long j;
    
    scanf("%ld%ld%ld",&n,&k,&s);
    if(s==N){
        for(i=0;i<k;i++){
            printf("%ld ",s);
        }if(k<n){
            for(j=i;i<n;i++)
                printf("%ld ",s-1);
        }
        
    }else{
        for(i=0;i<k;i++){
            printf("%ld ",s);
        }if(k<n){
            for(j=i;i<n;i++)
                printf("%ld ",s+1);
        }
    }


    printf("\n");
    return 0;
}
