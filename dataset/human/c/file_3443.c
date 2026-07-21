#include<stdio.h>

int main(void){
    int N, i, aa = 0, b, answer = 0;
    long int K;
    scanf("%d %ld", &N, &K);
    int A[N], check[N], jyun[N], recheck[N];
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
        check[i] = 0;
        jyun[i] = 0;
        recheck[i] = 0;
    }
    //ループの開始地点を探す
    b = 1;
    int c = 0, start = 0;
    while(aa == 0){
        b -= 1;
        if(check[b] > 0){
            aa += 1;
            start = b; 
            jyun[c] += b + 1;     //2回目の町-1
            break;
        }
        else{
        jyun[c] += b + 1;
        c += 1;
        check[b] += 1;
        b = A[b];
        }
    }

    int roop = 0, next = start + 1, yobun;
    if(K <= c){
        answer = jyun[K];
    }
    else{
        long int x;
        aa = 0;
        while(aa == 0){
            next -= 1;
            if(recheck[next] > 0){
                aa += 1;
                break;
            }
            else{
                roop += 1;
                recheck[next] += 1;
                next = A[next];
            }
        }
        yobun = c - roop;
        K -= yobun;
        K = K % roop;
        x = K + yobun;
        answer = jyun[x];
    }
    printf("%d\n", answer);
    return 0;

}
