#include <stdio.h>

int main()
{
    int n, flag;
    while(scanf("%d", &n) == 1)
    {
        flag = 0;
        while(n > 0)
        {
            int m = n % 10;
            if(m == 9)
            {
                flag = 1;
                break;
            }
            n /= 10;
        }
        printf("%s\n", flag == 1? "Yes":"No");
    }
    return 0;
}
