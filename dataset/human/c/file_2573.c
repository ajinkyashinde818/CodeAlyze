#include<stdio.h>
int main(void){
  char s[4];
  char t[]="abc";
  int count=0,i,j;
  scanf("%s",s);
  
 for(j=0;j<3;j++){
  for(i=0;i<3;i++){
  if(s[i]==t[j]){
    count++;
  t[j]='0';
  }
  }
 }
   if(count==3)
     printf("Yes");
   else
     printf("No");
  return 0;
}
