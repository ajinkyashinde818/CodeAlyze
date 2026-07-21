#include<stdio.h>
int main(){
    int k,s,a,b,c,cnt=0;
    scanf("%d %d", &k, &s);
    for(a=0; a<=k; a++){
        for(b=0; b<=k; b++){
            c=s-a-b;
            if(c<=k && c>=0)
              cnt+=1;
        }
    }
    printf("%d",cnt);
    return 0;
}
