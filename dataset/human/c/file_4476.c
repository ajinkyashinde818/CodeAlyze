#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int d[2][1000];
    scanf("%d",&n);
    int cnt=0;
    int mode;
    mode=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&d[0][i],&d[1][i]);
        if(d[0][i]==d[1][i]){
            cnt++;
        }else{
            cnt=0;
        }
        if(cnt==3){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");

    return 0;
}
