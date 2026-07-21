#include <string.h>
#include <stdio.h>

int main()
{   char s[100001];
    scanf("%s",s);
    for(int i=strlen(s)-1;i>=0;){
        if(s[i]=='r'&&s[i-1]=='e'&&s[i-2]=='s'&&s[i-3]=='a'&&s[i-4]=='r'&&s[i-5]=='e'){
            i=i-6;
        }else if(s[i]=='e'&&s[i-1]=='s'&&s[i-2]=='a'&&s[i-3]=='r'&&s[i-4]=='e'){
            i=i-5;
        }else if(s[i]=='r'&&s[i-1]=='e'&&s[i-2]=='m'&&s[i-3]=='a'&&s[i-4]=='e'&&s[i-5]=='r'&&s[i-6]=='d'){
            i=i-7;
        }else if(s[i]=='m'&&s[i-1]=='a'&&s[i-2]=='e'&&s[i-3]=='r'&&s[i-4]=='d'){
            i=i-5;
        }else{
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
