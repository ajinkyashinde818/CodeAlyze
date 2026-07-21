#include<stdio.h>
#include<string.h>

int main(void)
{
char s[4];
gets(s);
if(strchr(s, 'a')!=NULL&&strchr(s, 'b')!=NULL&&strchr(s, 'c')!=NULL)
{
printf("Yes\n");
}else{
printf("No\n");
}
return 0;
}
