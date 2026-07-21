#include<stdio.h>

int main (){
char s[5];
scanf("%s",s);
int i=0;
int flag[3]={};
do {
  if(s[i]=='a')flag[0]++;
  if(s[i]=='b')flag[1]++;
  if(s[i]=='c')flag[2]++;
  i++;
} while(s[i]!='\0');


if(flag[0]==1 && flag[1]==1 && flag[2]==1)printf("Yes\n");
else printf("No\n");
return 0;
}
