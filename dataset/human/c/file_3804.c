#include <stdio.h>
#include <limits.h>

int main(){
    long int A;
    long int B;
    
    long int a;
    long int b;
    int z=1;
    
    long int ans;
    
    scanf("%ld",&A);
    scanf("%ld",&B);
    
    if(A>B){
        a = A;
        b = B;
    }else{
        a = B;
        b = A;
    }
    
    while(z != 0){
        z = a%b;
        a = b;
        if(z==0){
            break;
        }
        b = z;
    }
        
    ans = (A/b)*B;    
        
    printf("%ld\n",ans);
    
    return 0;
}
