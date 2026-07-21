#include<stdio.h>

int gcd(int x, int y);  // 最大公約数を求める関数

int main()
{
    int x, y, K;
    int gcd_num;
    int A[100];
    int j = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &K);
    gcd_num = gcd(x, y);
    for(int i = 1; i <= gcd_num; i++){
        if( gcd_num % i == 0){
            A[j] = i;
            j++;
        }
    }

    printf("%d\n", A[j- K]);

    return 0;
}

// 最大公約数を求める関数
int gcd(int x, int y)
{
    int r;

    if(x == 0 || y == 0)  // 引数チェック
    {
        fprintf(stderr, "引数エラーです。\n");
        return 0;
    }

    // ユーグリッドの互除法
    while((r = x % y) != 0)  // yで割り切れるまでループ
    {
        x = y;
        y = r;
    }
    return y;
}
