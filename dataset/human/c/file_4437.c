#include <stdio.h>

int main(){

    int num;

    scanf("%d", &num);

    int D1[num], D2[num];
    
    for(int i=0; i<num; i++){
        scanf("%d", &D1[i]);
        scanf("%d", &D2[i]);
    }

    int max = 0, cnt = 0;

    int allFlag = 1;

    for(int i=0; i<num; i++){
        if(D1[i] == D2[i]){
            cnt++;
        }else{
            if(max<cnt){
                max = cnt;
            }
            allFlag = 0;
            cnt = 0;
        }
    }

    if(allFlag == 1){
        max = cnt;
    }

    if(max >= 3){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
