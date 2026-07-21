#include <stdio.h>
#include <string.h>
int main(void){
    char s[100001];
    scanf("%s",s);
    int len=strlen(s);
    while(len!=0){
        if((s[len-5]=='d' && s[len-4]=='r' && s[len-3]=='e' && s[len-2]=='a' && s[len-1]=='m') || (s[len-5]=='e' && s[len-4]=='r' && s[len-3]=='a' && s[len-2]=='s' && s[len-1]=='e')) s[len-5]='\0';
        else if(s[len-6]=='e' && s[len-5]=='r' && s[len-4]=='a' && s[len-3]=='s' && s[len-2]=='e' && s[len-1]=='r') s[len-6]='\0';
        else if(s[len-7]=='d' && s[len-6]=='r' && s[len-5]=='e' && s[len-4]=='a' && s[len-3]=='m' && s[len-2]=='e' && s[len-1]=='r') s[len-7]='\0';
        else{
            printf("NO");
            return 0;
        }
        len=strlen(s);
    }
    printf("YES\n");
    return 0;
}
