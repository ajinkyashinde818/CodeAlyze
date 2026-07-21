#include <stdio.h>
int main(int argc, const char * argv[]) {
    long int t, n, m, p;
    long int z, w;
    scanf("%ld%ld", &n, &m);                           //用输入函数，在键盘上输入两个值
    w = n * m;
    if (n < m)                                        //判断两个数的大小，必须是较大的数除去较小的数
    {
        p = n;
        n = m;
        m = p;
    }
    while (m != 0)                                    //使用循环，用辗转相除法求出最大公约数
    {
        t = n % m;
        n = m;
        m = t;
    }
    z = w / n;                                       //利用求出的最大公约数求出最小公倍数
    printf("%ld",z);
    return 0;
}
