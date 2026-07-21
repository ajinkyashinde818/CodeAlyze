#include<stdio.h>
int main(){
    int n, k, c;
    int r[2<<17];
    scanf("%d %d %d",&n,&k,&c);
    char s[2<<17];
    scanf("%s",s);
    int p = k;
    for(int i = n; i-->0;){
        if(s[i] == 'o'){
            r[i] = p--;
            i -= c;
        }
    }
    p = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            if(r[i] == ++p)
                printf("%d\n",i+1);
                i += c;
        }
    }
    return 0;
}
