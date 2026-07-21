#include<stdio.h>

int main(void){
    int n = 0;
    scanf("%d", &n);
    char a[n];
    scanf("%s", a);
    int k = 0;
    scanf("%d", &k);
    char b;
    b = a[k-1];
    for(int i=0; i<n; i++){
        if(a[i] != b){
            a[i] = '*';
        }
    }
    printf("%s", a);

    return 0;
}
