#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    // Your code here!
    char s1[300001];
    char s2[300001];
    int q;
    int t,f;
    char c;
    
    int flag=0;
    int s1len=0, s2len=0;
    
    scanf("%s", s1);
    s1len=strlen(s1);
    scanf("%d", &q);
    
    for(int i = 0; i < q; i++){
        scanf("%d", &t);
        if(t==1){
            flag = 1-flag;
        }else{
            scanf("%d %c", &f, &c);
            if(f-flag==1){
                s2[s2len]=c;
                s2[s2len+1]='\0';
                s2len++;
            }else{
                s1[s1len]=c;
                s1[s1len+1]='\0';
                s1len++;
            }
        }
    }
    
    if(flag == 0){
        for(int i=s2len-1; i>=0; i--){
            printf("%c",s2[i]);
        }
        for(int i=0; i<s1len; i++){
            printf("%c",s1[i]);
        }
    }else{
        for(int i=s1len-1; i>=0; i--){
            printf("%c",s1[i]);
        }
        for(int i=0; i<s2len; i++){
            printf("%c",s2[i]);
        }
    }
}
