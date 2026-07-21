#include<stdio.h>

int main(){

    int min;
    int maxd;
    int t;
    int n, i;
    scanf("%d\n", &n);
    scanf("%d\n", &min);
    for(i = 2; i <= n; i++){
        scanf("%d\n", &t);
        if(i==2){
            maxd = t - min;
        }
        if((t - min)>maxd)
            maxd = t - min;
        if(t < min)
            min = t;
    }
    printf("%d\n", maxd);

}
