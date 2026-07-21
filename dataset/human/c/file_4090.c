#include<stdio.h>
int main(){
    int a,b, k;
    scanf("%d %d %d", &a, &b, &k);
    int d[101];

    int n = 0;
    for(int i=1; i<101; i++){
        if(a%i==0 && b%i==0){
            d[n]=i;
            n++;
        }
    }
    printf("%d\n", d[n-k]);
    return 0;
}
