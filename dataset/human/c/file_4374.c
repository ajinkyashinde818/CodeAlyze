#include <stdio.h>
#include <math.h>
#include<string.h>
int main(){
    int n, d, e, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &d, &e);
        if(d == e){
            count++;
        }
        else{
            count = 0;
        }
        if(count == 3){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
