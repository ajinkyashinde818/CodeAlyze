#include <stdio.h>

int main(void){
    int K,N;
    int A[2*10*10*10*10*10];
    
    int maxlength=0,length=0,i,min;
    
    scanf("%d",&K);
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    
    for(i=0;i<N;i++){
        if(i!=N-1){
            length=A[i+1]-A[i];
        }else{
            length=(K-A[N-1])+A[0];
        }
        
        if(maxlength<length){
                maxlength=length;
        }
    }
    
    min=K-maxlength;
    
    printf("%d\n",min);
    
    return 0;
}
