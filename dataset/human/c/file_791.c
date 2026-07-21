#include <stdio.h>

int minimum(int a, int b) { return a < b ? a : b; }

int main(){
    int D, G, p[10], c[10], i, j, k, a, ans=100000, num, max;

    scanf("%d %d", &D, &G);

    for(i=0; i<D; i++){
        scanf("%d %d", &p[i], &c[i]);
    }

    for(i=0; i<(1<<D); i++){
        a=0;
        num=0;
        max=-1;
        for(j=0; j<D; j++){
            if((i>>j) & 1){
                a += p[j]*(j+1)*100 + c[j];
                num += p[j];
            }
            else
                max = j;
        }

        j=0;
        while(a < G && j < p[max]){
            a += (max+1)*100;
            num++;
            j++;
        }

        if(a >= G)
            ans = minimum(ans, num);
    }

    printf("%d\n", ans);

    return 0;
}
