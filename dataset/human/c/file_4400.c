#include <stdio.h>

int main(void){
    int N;
    int D[100][2];
    int J[100] = {0};
    //input
    scanf("%d", &N);
    int i;
    for(i=0;i<N;i++){
        scanf("%d %d", &D[i][0], &D[i][1]);
        if(D[i][0] == D[i][1]) J[i] =1;
    }

    //check
    for(i=0;i<N;i++){
        if(i<= N-2){
            if(J[i]*J[i+1]*J[i+2] == 1){
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
    return 0;
}
