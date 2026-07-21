#include <stdio.h>
int main(void){
    int k,s,x,y,cnt=0;
    scanf("%d%d",&k,&s);
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            if(x+y<=s && s-x-y<=k) cnt++;
        }
    }
    printf("%d",cnt);
}
