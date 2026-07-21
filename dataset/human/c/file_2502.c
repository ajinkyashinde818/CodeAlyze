#include<stdio.h>
int main(void){
char s[3];
int i,r=0,l=0,j=0;
scanf("%s",s);
for(i=0;i<3;i++){
if(s[i]=='a')
r++;
else if(s[i]=='b')
l++;
else if(s[i]=='c')
j++;
}
if(r==1&&l==1&&j==1)
puts("Yes");
else
puts("No");

return 0;
}
