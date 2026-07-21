#include <stdio.h>

int main(){

    int n, d1, d2, count = 0, flag = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &d1);
        scanf("%d", &d2);
        if(d1 == d2){
            count += 1;
        }else{
            count = 0;
        }
        if(count >= 3){
            flag = 1;
            break;
        }
    }


    if(flag == 1){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}
