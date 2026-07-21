#include <stdio.h>
    #include <stdlib.h>
     
    int main() {
     
        int k,s;
        int x,y,z;
        int cnt = 0;

        scanf("%d %d",&k,&s);
        for(x=0;x<=k;x++){
            for(y=0;y<=k;y++){
                if(0 <= (s-(x+y)) && (s-(x+y)) <= k){cnt++;}
            }
        }
        printf("%d",cnt);

        return 0;     
    }
