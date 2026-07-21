#include <stdio.h>

int main(void){
    char str[3];
    int mem[3] = {0};
    scanf("%s",str);
    for(int i = 0;i < 3;i++){
        if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c'){
            if(mem[((int)str[i]) % 97] < 1){
            mem[str[i] % 97]++;
            } else {
                printf("No");
                return 0;
            }
        } else {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}
