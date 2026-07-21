#include<stdio.h>

int main(){
    int k,s;
    int cnt=0;
    int x,y,z;
    scanf("%d %d",&k,&s);
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            z = s - x - y;
            if(z>=0&&z<=k)
                cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
