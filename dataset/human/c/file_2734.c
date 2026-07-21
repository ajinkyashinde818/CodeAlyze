#include<stdio.h>

int main(void){
        int k, s, ans=0;;
        scanf("%d %d", &k, &s);
        for(int i=0; i<=k; i++) for(int j=0; j<=k; j++) ans += (0<=s-i-j)&&(s-i-j<=k);
        printf("%d\n", ans);
        return 0;
}
