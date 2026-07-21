#include <stdio.h>
#include <string.h>

int main(void){
    // Your code here!
    char str[100001];
    char *test[4] = {"dreamer","dream","eraser","erase"};
    
    scanf("%100000s",str);
    
    for(int i = strlen(str)-1;i >= 4;){
        int j,flag = 0;
        for(j = 0;j<4;j++){
            int k,len = strlen(test[j]);
            for(k=0;test[j][k]!='\0';k++){
                if(test[j][len-k-1] != str[i-k]){
                    break;
                }
            }
            if(k==len){
                //printf("j_%d\n",j);
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            printf("NO\n");
            return 0;
        }
        i -= strlen(test[j]);
    }
    
    printf("YES\n");
    return 0;
}
