#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

int cp(const int *a,const int *b){
    return *a-*b;
}

int main(void){
    int r,g,b,n;
    scanf("%d %d %d %d",&r,&g,&b,&n);
    int cnt=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int bb=n-(i*r+j*g);
            int s=bb+i*r+j*g;
            if(bb<0)continue;
            if(s==n&&bb%b==0)cnt++;
            if(j*g>n||i*r>n)break;
        }
        if(i*r>n)break;
    }
    printf("%d\n",cnt);
    return 0;
}
