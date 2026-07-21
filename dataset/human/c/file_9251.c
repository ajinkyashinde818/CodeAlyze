#include <stdio.h>
int main(void)
{
    int n, k, count=0;
    scanf("%d%d", &n, &k);

    int h[n];
    for(int i=0; i<n; i++){
        scanf("%d", &h[i]);
        if(k<=h[i]){
        count++;
        }
    }
    printf("%d", count);

}
