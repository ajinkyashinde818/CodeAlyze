#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(void){
    char divide[4][8] = {"dream\0","dreamer\0","erase\0","eraser\0"};
    int divide_S[4] = {5,7,5,6};
    char S[100001]; 
    int S_size;
    scanf("%s",&S);
    S_size = strlen(S);
    // printf("%d\n",S_size);
    
    int i = 0;
    int flag1 = 1, flag2 = 1;
    while(flag1 == 1){
 
        for(i = 0;i < 4;i++){
            // printf("%s",&divide[i][0]);
            // printf("\n%s",&S[S_size - divide_S[i]]);
            // printf("\n%d",strcmp(&S[S_size - divide_S[i]],&divide[i][0]));
            flag2 = 0;
            if(S_size >= divide_S[i] && strcmp(&S[S_size - divide_S[i]],&divide[i][0]) == 0){
                S[S_size - divide_S[i]] = '\0';
                S_size = strlen(S);
                flag2 = 1;
                break;    
                }   
            
            }
 
        if(S_size == 0){
            printf("YES\n");
            return 0;
        }
 
        if(i == 4 && flag2 == 0){
                flag1 = 0;    
            }
    }
    printf("NO\n");
 
    return 0;
}
