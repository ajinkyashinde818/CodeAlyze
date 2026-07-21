#include<stdio.h>
#include<string.h>

int main(){
    char s[100000];
    scanf("%s",s);
    int len=strlen(s);

    int i=0;
    while(1){
        if(s[i]=='d'&&s[i+1]=='r'&&s[i+2]=='e'&&s[i+3]=='a'&&s[i+4]=='m'){
            if(s[i+5]=='e'&&s[i+6]=='r'){
                if(s[i+7]=='a'&&s[i+8]=='s'&&s[i+9]=='e'){
                    i+=5;
                }else if(s[i+7]=='a'&&s[i+8]=='s'&&s[i+9]=='e'&&s[i+10]=='r'){
                    i+=5;
                }else{
                    i+=7;
                }
            }else{
                i+=5;
            }
        }else if(s[i]=='e'&&s[i+1]=='r'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='e'){
            if(s[i+5]=='r'){
                if(s[i+6]=='a'&&s[i+7]=='s'&&s[i+8]=='e'){
                    i+=5;
                }else if(s[i+6]=='a'&&s[i+7]=='s'&&s[i+8]=='e'&&s[i+9]=='r'){
                    i+=5;
                }else{
                    i+=6;
                }
            }else{
                i+=5;
            }
        }else{
            break;
        }
    }

    if(i==len){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
