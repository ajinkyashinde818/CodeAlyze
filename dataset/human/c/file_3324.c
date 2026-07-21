#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000]={NULL};
    int n;

    scanf("%s", s);
    n = strlen(s)-1;

    while(1){
        if(s[n-5]=='e'&&s[n-4]=='r'&&s[n-3]=='a'&&s[n-2]=='s'&&s[n-1]=='e'&&s[n]=='r'){
            n-=6;
        }else if(s[n-4]=='e'&&s[n-3]=='r'&&s[n-2]=='a'&&s[n-1]=='s'&&s[n]=='e'){
            n-=5;
        }else if(s[n-6]=='d'&&s[n-5]=='r'&&s[n-4]=='e'&&s[n-3]=='a'&&s[n-2]=='m'&&s[n-1]=='e'&&s[n]=='r'){
            n-=7;
        }else if(s[n-4]=='d'&&s[n-3]=='r'&&s[n-2]=='e'&&s[n-1]=='a'&&s[n]=='m'){
            n-=5;
        }else{
            printf("NO");
            return 0;
        }
        if(n==-1)break;
    }
    printf("YES");
    return 0;
}
