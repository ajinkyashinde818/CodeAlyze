#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,x;
    i=1;
    while(1){
        scanf("%d",&x);
        if(x==0){break;}
        if((x>=0)&&(x<=10000)){
            printf("Case %d: %d\n",i,x);
        }
        i++;
    }
    return 0;
}
