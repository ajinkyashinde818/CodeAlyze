#include<stdio.h>

int main(){
    int r,g,b,n,i,count=0,x;
    scanf("%d %d %d %d",&r,&g,&b,&n);
    for(i=0;i<=n/r;i++){
        for(int j=0;j<=n/g;j++){
            x = n-(i*r+j*g);
            if(x % b != 0)continue;
            if(x < 0)break;
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
