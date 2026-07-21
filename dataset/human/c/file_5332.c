#include <stdio.h>
#include <stdlib.h>

int N; //参考書の数
int M; //アルゴリズムの数
int X; //目標値

int cost[12];
int shuukudo[12][12];

int shuuku_hante[12];

int konyu(int bit){

    for(int i = 0;i < 12;i++)shuuku_hante[i] = 0;
    int sum_cost =  0;

    int _bit;
    for(int i = 0;i < N;i++){
        _bit = 1 << i;
        if(( bit & _bit ) != 0){
            sum_cost += cost[i];
            for(int j = 0;j < M;j++){
                shuuku_hante[j] += shuukudo[i][j];
            }
        }
    }

    for(int i = 0;i < M;i++){
        if(shuuku_hante[i] < X){
            //printf("-1 -1 cost :%d\n",sum_cost);
            return -1;
        }
    }

    //printf("ok cost :%d\n",sum_cost);

    return sum_cost;
    
}

int main(void) {

    scanf("%d %d %d",&N,&M,&X);

    for(int i = 0;i < 12;i++)shuuku_hante[i] = 0;

    for(int i = 0;i < N;i++){
        
        scanf("%d",&cost[i]);
        //printf("%d cost:%d\n",i,cost[i]);

        for(int j = 0;j < M;j++){
            scanf("%d",&shuukudo[i][j]);
            //printf("shuukudo:%d\n",shuukudo[i][j]);
            shuuku_hante[j] += shuukudo[i][j];
        }
    }

    // 事前に習熟度が高くないとき
    for(int i = 0;i < M;i++){
        if(shuuku_hante[i] < X){
            printf("-1\n");
            return 0;
        }
    }

    // 教科書を買う通りは??
    int bit_Max = 1;
    for(int i = 0; i < N - 1; i++){
        bit_Max = bit_Max << 1;
        bit_Max++;
    }

    int minmin = 0;
    int a;
    for(int i = 0; i <= bit_Max;i ++){
        a = konyu(i);
        if(a != -1){
            if(a != 0 && minmin == 0){
                minmin = a;
            }else{
                if(a < minmin){
                    minmin = a;
                }
            }
        }
    }

    printf("%d\n",minmin);

    return 0;
}
