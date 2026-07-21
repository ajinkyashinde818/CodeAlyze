#include <stdio.h>
#include <string.h>
int main(void){
 int i,j;
 char c;
 char s[101];
 char t[101];
 scanf("%s",s);
 scanf("%s",t);
 for(i=1;i<strlen(s);i++){
  for(j=i;j>0;j--){
   if(s[j-1]>s[j]){
    c=s[j-1];
    s[j-1]=s[j];
    s[j]=c;
   }
  }
 }
 for(i=1;i<strlen(t);i++){
  for(j=i;j>0;j--){
   if(t[j-1]<t[j]){
    c=t[j-1];
    t[j-1]=t[j];
    t[j]=c;
   }
  }
 }
 printf(strcmp(s,t)<0?"Yes":"No");
 return 0;
}
