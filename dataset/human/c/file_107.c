#include<stdio.h>
int main()
{
    int R, G, B, N;
    int count = 0;
    // 整数の入力
    scanf("%d", &R);
    scanf("%d", &G);
    scanf("%d", &B);
    scanf("%d", &N);

    for (int r = 0; r * R <= N; r++) {
        for (int g = 0; g * G <= (N - r * R); g++) {
            int n = N - (r * R) -  (g * G);
//    printf("%d %d %d\n", r, g, n);
            if ((n % B) == 0) count++;
        }
    }
    
    
    printf("%d\n", count);
/*
    // スペース区切りの整数の入力
    scanf("%d %d",&b,&c);
    // 文字列の入力
    scanf("%s",s);
    // 出力
    printf("%d %s\n",a+b+c,s);
*/
    return 0;
}
