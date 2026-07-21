#include <stdio.h>

int main(void){
    
    int a,b,k,count;
    count=0;
    scanf("%d %d %d",&a,&b,&k);
    
    for(int i=a; i>0; i--){
        if(a%i==0 && b%i==0){
            count++;
            
            if(count==k){
                printf("%d",i);
                return 0;
            }
        }
    }
}
