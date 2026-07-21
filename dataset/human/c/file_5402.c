#include<stdio.h>

int main(void){
    int N, X, M, i;
    scanf("%d %d %d", &N, &M, &X);
    int A[N][M], C[N];
    int exp[M], reexp[M];
    for(i = 0; i<M; i++){
        exp[i] = 0;
        reexp[i] = 0;
    }
    for(i = 0; i < N; i++){
        scanf("%d", &C[i]);
        for(int j = 0; j < M; j++){
            scanf("%d", &A[i][j]);
            exp[j] += A[i][j];
        }
    }
    //計算を軽くするため、２の12乗までを手動入力
    int ns[13] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    
    //"exp"を使ってまず目標を達成できるかどうかを評価
    int zzzz = 0;
    for(i = 0; i<M; i++){
        if(exp[i] < X) zzzz += 1;
    }
    if(zzzz >= 1) printf("-1\n");
    else{
    //まず全部試すための回数を求める
    int two = 1;
    for(int j = 0; j <= N; j++){
        two *= 2;
    }
    //上記で求めた数を使い全通り試す
        int cost, x, ka, check = 0, recost = 100000000;
    for(int k = 1; k < two - 1; k++){
        for(int m = 0; m < M; m++){
            reexp[m] = 0;
        }
        check = 0;
        cost = 0;
        ka = k;
        for(i = 0; i < N; i++){
            x = N - i;
            if(ka >= ns[x]){
                ka -= ns[x];
                for(int z = 0; z < M; z++)
                    reexp[z] += A[i][z];
                cost += C[i];
            }
        }
        for(int l = 0; l < M; l++){
            if(reexp[l] < X) check += 1;
        }
        if(check == 0){
            if(cost < recost) recost = cost;
        }
    }
        printf("%d", recost);
        
    }
    return 0;

}
