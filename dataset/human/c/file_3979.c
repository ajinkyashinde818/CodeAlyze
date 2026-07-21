#include <stdio.h>

int main()
{
    int a, b, k;
    int n[1000000] = {0};
    int j = 0;
    scanf("%d%d%d", &a, &b, &k);
    for(int i = 1; i <= a || i <= b; i++){
        if(a%i == 0 && b%i == 0){
            n[j] = i;
            j++;
        }
    }
    printf("%d\n",n[j-k]);
    return 0;
}
