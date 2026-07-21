#include <stdio.h>
#include <string.h>
int main(void){
    // Your code here!
    char s[100001];
    gets(s);
    
    
    for(int i=0;i<strlen(s);i++){
        
        if(strncmp(s+i,"dreamer",7)==0 && s[i+7]!='a'){
            i+=6;
        }else if(strncmp(s+i,"dream",5)==0){
            i+=4;
        }else if(strncmp(s+i,"eraser",6)==0  && s[i+6]!='a'){
            i+=5;
        }else if(strncmp(s+i,"erase",5)==0){
            i+=4;
        }else{
            printf("NO\n");
            return 0;
            break;
        }
        
        
    }
    printf("YES\n");
    return 0;
}
