#include <stdio.h>


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int h[n];
    for (int i=0; i < n; i++){
        scanf("%d", &h[i]);
    }
    
    int cnt = 0;
    for (int i=0; i < n; i++){
        if (k <= h[i])
            cnt++;
    }


    printf("%d\n", cnt);



    return 0;
}
