#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[200000];
int sudeni_tsuita[200000];

int main(void) {

    int N;
    unsigned long int K;
    unsigned long int iter;

    scanf("%d %lu",&N,&K);

    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
        sudeni_tsuita[i] = 0;
    }

    int next_index = 1;
    int loop_count = 0;
    for(iter = 0;iter < K;iter++){
        //printf("twon %d\n",next_index);
        if(sudeni_tsuita[next_index - 1] == 3){
            //printf("loop %d,\n",loop_count);
            int nokori_teleport = (K - iter)%loop_count;
            //printf("nokori_teleport: %d\n",nokori_teleport);
            //printf("visit: %d\n",next_index);
            //next_index = A[next_index-1];
            for(int i = 0;i < nokori_teleport;i++){
                //printf("visit: %d\n",next_index);
                next_index = A[next_index-1];
            }
            break;
        }

        sudeni_tsuita[next_index - 1] += 1;
        //printf("visit: %d\n",next_index);
        next_index = A[next_index-1];
        if(sudeni_tsuita[next_index - 1] == 2){
            loop_count ++;
        }
    }

    printf("%d\n",next_index);
    
}
