#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
    int k, s;
    scanf("%d %d", &k, &s);

    int cnt = 0;
    for (int i=0; i <= k;i++){
        for (int j=0; j <= k; j++){
            if (0 <= s-i-j && s-i-j <= k) cnt++;
        }
    }

    printf("%d\n", cnt);    


    return 0;
}
