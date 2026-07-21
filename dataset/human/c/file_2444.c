#include <stdio.h>
int main(void){
    // Your code here!
    char s[3];
    int i,flaga=0,flagb=0,flagc=0;
    
    
    scanf("%s",s);
    for(i=0;i<3;i++){
        if(s[i]=='a'){
        flaga++;
        }
        else if(s[i]=='b'){
        flagb++;
        }
        else{
            flagc++;
        }
    }
    
    if(flaga==1&&flagb==1&&flagc==1){
        printf("Yes");
    }
    else{
        printf("No");
    }
    
    return 0;
}
