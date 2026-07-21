#include<stdio.h>

int main(){
        int n, k;
        char s[11];
        scanf("%d %s %d", &n, s, &k);
        for(int i=0; i<n; i++){
                if(s[i]==s[k-1]) putchar(s[i]);
                else putchar('*');
        }
        puts("");
        return 0;
}
