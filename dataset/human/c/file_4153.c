#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    int r = a%b;
    if(r == 0) return b;
    else return gcd(b, r);
}
int main()
{
    int a, b, k;
    int r, j;
    int *arr;
    
    scanf("%d%d%d", &a, &b, &k);
    r = gcd(a,b);
    arr = malloc(sizeof(int) * r);
    for(int i=0;i<r;i++) arr[i] = 0;
    for(int i=1;i<=r;i++){
        if(r%i == 0) arr[i-1] = i;
    }
    j = r-1;
    while(k != 0){
        if(arr[j] != 0) k--;
        j--;
    }
    printf("%d\n", arr[++j]);
    return 0;
}
