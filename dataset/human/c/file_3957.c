#include <stdio.h>
#include <stdlib.h>

int gcc(int a, int b){
    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    int a, b, i, j, k;
    int cc[100] = {0};
    scanf("%d %d %d", &a, &b, &k);
    int g = gcc(a, b);
    j = 0;
    if(g==1){
        if(k==1) printf("1");
    }else{
        for(i=g;i>=1;i--){
            if(g % i == 0){
                cc[j] = i;
                j++;
            }
        }
        int x = cc[k-1];
        printf("%d", x);
    }
    return 0;
}
