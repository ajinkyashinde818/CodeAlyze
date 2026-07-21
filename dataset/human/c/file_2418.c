#include <stdio.h>

int main(void){
    char alpha;
    int i, flag[3];
    for(i = 0; i < 3; i++)
        flag[i] = 0;
    for(i = 0; i < 3; i++){
        alpha = getchar();
        switch (alpha) {
            case 'a':
                if(flag[0] > 0){
                    printf("No\n");
                    return 0;
                }
                else
                    flag[0]++;
                break;
            case 'b':
                if(flag[1] > 0){
                    printf("No\n");
                    return 0;
                }
                else
                    flag[1]++;
                break;
            case 'c':
                if(flag[2] > 0){
                    printf("No\n");
                    return 0;
                }
                else
                    flag[2]++;
                break;
        }
    }
    printf("Yes\n");
    return 0;
}
