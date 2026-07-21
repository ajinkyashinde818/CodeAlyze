#include<stdio.h>

int T;
long long A,B,C,D;

int main(){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
        if(A<B||D<B){
            printf("No\n");
        }else if(C<B){
            long long a=D,b=B;
            while(a%b>0){
                long long t=a%b;
                a=b;
                b=t;
            }
            long long c=B-b+(A%b);
            if(c>C){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        }else{
            printf("Yes\n");
        }
        
    }
    return 0;
}
