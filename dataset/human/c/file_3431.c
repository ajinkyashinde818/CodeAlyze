#include <stdio.h>
#include <string.h>

#define MAXSIZE 100000

int main(void){
    char s[MAXSIZE],d[]="dream",e[]="erase";
    scanf("%s",s);
    int len_s=strlen(s),p=0,i;
    while(p<len_s){
        if(s[p]=='d'){
            for(i=0;i<5;i++){
                if(s[p]==d[i]){
                    p++;
                }else{
                    printf("NO\n");
                    return 0;
                }
            }
            if(s[p]=='e'){
                p++;
                if(s[p]=='r'){
                    p++;
                    if(s[p]=='a') p-=2;
                }
            }
        }else if(s[p]=='e'){
            for(i=0;i<5;i++){
                if(s[p]==e[i]){
                    p++;
                }else{
                    printf("NO\n");
                    return 0;
                }
            }
            if(s[p]=='r'){
                p++;
            }
        }else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
