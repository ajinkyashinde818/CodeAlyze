#include <stdio.h>
int min(int a, int b){return (a>b)? b:a;}

int eaten[101]; //1-based 

int main(void){
    // Your code here!
    int N,D,X;
    scanf("%d %d %d",&N,&D,&X);
    
    int A;
    for(int i = 0; i < N; i++){
        scanf("%d",&A);
    
        for(int k = 0; k*A+1 <= D; k++){
            eaten[k*A+1] += 1;
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= D; i++){
        cnt += eaten[i];
    }
    
    printf("%d\n",X+cnt);

}
