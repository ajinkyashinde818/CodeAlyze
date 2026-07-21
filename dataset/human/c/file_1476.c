#include <stdio.h>

int main(void){
    char input[5];
    int ans;
    int i;
    ans = 0;
    scanf("%s", input);
    for (i = 0; i < 2; i++){
        if(input[i] == 57){
            printf("Yes\n");
            goto end;
            ans = 1;
        }
    }
    if(ans != 1){
        printf("No\n");
    }
end:
    return 0;
}
