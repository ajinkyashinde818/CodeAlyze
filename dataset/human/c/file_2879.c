#include <stdio.h>

int main(void){
    int k,s;
    int x,y,z;
    int sum = 0;
    int ans = 0;
    scanf("%d %d",&k,&s);
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            z = s - x - y;
            if(z >= 0 && z <= k) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
