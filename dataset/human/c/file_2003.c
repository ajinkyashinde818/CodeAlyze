#include <stdio.h>
#define Q1 0
#define Q2 1



int main(void){
    int A=0,B=0,C=0;
    int count = 0;
    int STATE = 1;
    scanf("%d %d %d",&A,&B,&C);
    
    
    while(1){
       //printf("%d\n",STATE);
        //printf("%d %d %d\n",A,B,C);
        //printf("count=%d\n",count);
        if(STATE == Q2){
            if(C>0){
                C-=1;
                count++;
                STATE = Q1;
            }else if(C==0&&B>0){
                B-=1;
                count++;
                if(B==0){
                    break;
                }
            }else{
                break;
            }
        }else if(STATE == Q1){
            if(A>0){
                A -= 1;
                STATE = Q2;
            }else if(B>0){
                B-=1;
                count++;
                STATE = Q2;
            }else{
                break;
            }
       } 
    }
    printf("%d\n",count);
    return 0;






}
