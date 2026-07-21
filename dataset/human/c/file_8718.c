#include<stdio.h>
#include<stdbool.h>


int main(void) {
    int n;
    scanf("%d", &n);
    int a[n+1];
    for(int i=1; i<n+1; i++) {
        scanf("%d", &a[i]);
    }
    int memo=1;
    int counter=0;
    int result;
    while(true) {
        memo = a[memo];
        counter++;
        if(memo == 2) {
            result = counter;
            break;
        }
        if(counter >= n) {
            result = -1;
            break;
        }
    }
    printf("%d", result);
    return 0;
}
