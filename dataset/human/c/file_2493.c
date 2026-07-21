#include <stdio.h>
int main(void){
    char str[5];
    scanf("%s", str);
    int a_cnt = 0;
    int b_cnt = 0;
    int c_cnt = 0;
    
    for(int i = 0; i < 3; i++){
        if(str[i] == 'a')       a_cnt++;
        if(str[i] == 'b')       b_cnt++;
        if(str[i] == 'c')       c_cnt++;
        
        // printf("%c ", str[i]);
    }
    // printf("\n");
    
    if(a_cnt != 1 || b_cnt != 1 || c_cnt != 1){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
}
