#include <stdio.h>
int twoCount(int tk,int ts){
    if(tk>=ts)
        return ts+1;
    else if(tk*2<ts)
        return 0;
    else
        return tk*2-ts+1;
}

int main(void){
    
    int k,s,cnt,st;
    scanf("%d",&k);
    scanf("%d",&s);
    cnt=0;
    if(k>s)
        st=s;
    else
        st=k;
    for(int i=st;i>=0;i--){
        cnt+=twoCount(k,s-i);
    }
    printf("%d",cnt);
    
}
