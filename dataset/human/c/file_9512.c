#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N,D,X;
    int A[100]={};
    int i=0;
    int j=0;
    int num=0;
    
    scanf("%d\n",&N);
    scanf("%d %d\n",&D,&X);
    while(1){
        scanf("%d\n",&A[i]);
        if(A[i]==1){
            num=D;    
        }else{
            if(D%A[i]==0){
                num=D/A[i];
            }else{
                num=1+D/A[i];
            }
        }
        X=X+num;
        //printf("%d\n",num);
        i++;
        if(N==i){
            break;
        }
    }

    /*for(i=0;i>=D;i++){
        num = D / A[i];
        cnt = cnt + num;
    }*/
    
    //printf("%d\n",N);
    //printf("%d\n",D);
    //printf("%d\n",X);
    //printf("%d\n",num);
    printf("%d\n",X);
    //printf("%d\n",num);
    
    return 0;
}
