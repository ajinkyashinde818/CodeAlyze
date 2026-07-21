#include <stdio.h>
int main(void)
{
    char s[3]={};
    scanf("%s",&s);
    if(s[0]=='a'&&s[1]=='b'&&s[2]=='c')printf("Yes");
    else if(s[0]=='a'&&s[1]=='c'&&s[2]=='b')printf("Yes");
    else if(s[0]=='b'&&s[1]=='a'&&s[2]=='c')printf("Yes");
    else if(s[0]=='b'&&s[1]=='c'&&s[2]=='a')printf("Yes");
    else if(s[0]=='c'&&s[1]=='a'&&s[2]=='b')printf("Yes");
    else if(s[0]=='c'&&s[1]=='b'&&s[2]=='a')printf("Yes");
    else printf("No");
    return 0;
}
