#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Your code here!
    int n;
    int i;
    int d[2];
    int cnt;

    cnt = 0;
    scanf("%d", &n);
    i = 0;
    while (i < n)
    {
        scanf("%d %d", d, d + 1);
        if (d[0] == d[1] && ++cnt == 3)
        {
            printf("Yes");
            return (0);
        }
        if (d[0] != d[1])
            cnt = 0;
        i++;
    }
    printf("No");
    
}
