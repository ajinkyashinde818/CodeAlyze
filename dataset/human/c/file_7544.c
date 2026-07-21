#include <stdio.h>
int main(int argc, const char * argv[]){
    int i=1;
    int t;
    int x[10001]={};
    while(1){
        scanf("%d", &x[i]);
        if (x[i]==0) {
            break;
        }
        i++;
    }
    for(t=1;t<i;t++){
        printf("Case %d: %d\n", t,x[t]);
    }
    return 0;
}
