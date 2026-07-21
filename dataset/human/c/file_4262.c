#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int N, M;
    int i, j;
    int *aM;
    int hole = 0;
    long long int *caseNum;
    
    scanf("%d",&N);
    scanf("%d",&M);
    aM = (int *)calloc(M, sizeof(int));
    caseNum = (long long int *)calloc(N, sizeof(long long int));
    
    for(i=0; i<M; i++){
        scanf("%d",&aM[i]);
    }
    
    caseNum[0] = 1;
    caseNum[1] = 2;
    for (j=0; j<M; j++) {
        if(aM[j] == 1){
            caseNum[0] = 0;
            caseNum[1] = 1;
            hole++;
        }
        if(aM[j] == 2){
            caseNum[1] = 0;
            hole++;
            break;
        }
        if(aM[j] > 2){break;}
    }
    
    for(i=2; i<N; i++){
        if(aM[hole] == i+1){
            caseNum[i] = 0;
            hole++;
        }else{
            caseNum[i] = (caseNum[i-1] + caseNum[i-2]) % 1000000007;
        }
    }
    
    printf("%lld\n", caseNum[N-1]);
    
    free(aM);
    free(caseNum);
    return 0;
}
