#include <stdio.h>

int main(){
    int n,a = 0;
    scanf("%d", &n);
    int d[n][2];
    for(int i = 0; i < n; i++){
        scanf("%d%d", &d[i][0],&d[i][1]);
    }
    for(int i = 0; i < n; i++){
        if(d[i][0] == d[i][1]){
            a++;
        }else{
            if(a < 3){
                a = 0;
            }
        }
    }
    if(a >= 3){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}
