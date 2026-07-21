#include <stdio.h>
#include <stdlib.h>

int main(void){
    int x,y,z,k,s,ans=0;
    scanf("%d %d",&k,&s);
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            z=s-(x+y);
            if(z>=0&&z<=k)ans++;
        }
    }
    printf("%d\n",ans);
    }
