#include <stdio.h>
int main(void){
    int n, d, x;
    int a[100+5];
    scanf("%d %d %d", &n, &d, &x);
    for(int i=0; i<n; i++)scanf("%d", &a[i]);
    
    for(int i=0; i<n; i++)x+=(1+(d-1)/a[i]);
    
    printf("%d\n", x);
    return 0;
}
