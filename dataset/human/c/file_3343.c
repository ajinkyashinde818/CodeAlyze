#include<stdio.h>
#include<string.h>
#define n 100000
int main(){
    char s[n];
    scanf("%s",s);
    long int m;
    m=strlen(s);
    long int i=m-1;
    int flag=0;
    while(flag==0 && i>=0){
        if(s[i]=='m'){
            if(s[i-1]!='a'||s[i-2]!='e'||s[i-3]!='r'||s[i-4]!='d')flag=1;
            else i-=5;
        }else if(s[i]=='r' && s[i-1]=='e'){
            if(s[i-2]=='m'){
                if(s[i-3]!='a'||s[i-4]!='e'||s[i-5]!='r'||s[i-6]!='d')flag=1;
                else i-=7;
            }else if(s[i-2]=='s'){
                if(s[i-3]!='a'||s[i-4]!='r'||s[i-5]!='e')flag=1;
                else i-=6;
            }else{
                flag=1;
            }
        }else if(s[i]=='e'){
            if(s[i-1]!='s'||s[i-2]!='a'||s[i-3]!='r'||s[i-4]!='e')flag=1;
            else i-=5;
        }else{
            flag=1;
        }
    }
    if(flag==0){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
