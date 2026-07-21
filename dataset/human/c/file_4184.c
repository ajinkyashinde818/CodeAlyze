#include <stdio.h>
#include <math.h>
int main(void){
    // Your code here!
    int a,b,k;
    
    scanf("%d %d %d",&a,&b,&k);
    int n=0;
    
    for(int i=a;i>0;i--){
        if(a%i==0 & b%i==0)n++;
        if(n==k){
            printf("%d\n",i);
            return 0;
        }
    }
    
    //printf("%d\n",c);
    
}
