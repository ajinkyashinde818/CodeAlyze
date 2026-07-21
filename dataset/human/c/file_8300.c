#include<stdio.h>
int main()
{
    int a,b,c,N,K;
    char s[101];
    // 整数の入力
    scanf("%d", &N);
    scanf("%s",s);
    scanf("%d", &K);
//    scanf("%d", &c);

    for (int i = 0; i < N; i++) {
        if (s[i] == s[K - 1]) {
            printf("%c", s[i]);
        }
        else
            printf("*");
    }
    printf("\n");
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
