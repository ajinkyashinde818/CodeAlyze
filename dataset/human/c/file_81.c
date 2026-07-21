#include<stdio.h>

int main(void){
    int r,g,b,n;
    int ans = 0;
    scanf("%d%d%d%d", &r, &g, &b, &n);
    for(int i=0; i<=3000; i++){
        if(i*r > n) break;
        for(int j=0; j<=3000; j++){
            if(i*r + j*g <= n && (n-(i*r + j*g)) % b == 0) ans+=1;
        }
    }
    printf("%d\n",ans);
}
