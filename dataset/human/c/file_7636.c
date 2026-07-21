#include <stdio.h>
#include <stdbool.h>

int main(){
    bool on = true;
    int x[10001] = {0};
    int i = 1;
    int temp = 0;
    while(on == true){
        scanf("%d",&x[temp]);
        if(x[temp] == 0){
            on = false;
        }
        temp++;
    }
    i = 0;
    while(x[i] != 0){
        printf("Case %d: %d\n",i + 1,x[i]);
        i++;
    }
    return 0;
}
