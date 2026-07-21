#include<stdio.h>
#include<string.h>
int main(void){
  int i,j;
  char s[101],t[101];
  char b;
  int ls,lt;
  int x=0;
  
  scanf("%s",s);
  scanf("%s",t);
  
  ls=strlen(s);
  lt=strlen(t);
  
  for(i=0;i<ls;i++){
    for(j=i;j<ls;j++){
      if(s[i]>s[j]){
        b=s[i];
        s[i]=s[j];
        s[j]=b;
      }
      else{}
    }
  }
  
  for(i=0;i<lt;i++){
    for(j=i;j<lt;j++){
      if(t[i]<t[j]){
        b=t[i];
        t[i]=t[j];
        t[j]=b;
      }
      else{}
    }
  }
  
  for(i=0;i<101;i++){
    if(s[i]==t[i]){}
    if(s[i]<t[i]){
      x=1;
      break;
    }
    if(s[i]>t[i]){
      x=0;
      break;
    }
  }
  
  if(x==0)printf("No\n");
  if(x==1)printf("Yes\n");
  
  return 0;
}
