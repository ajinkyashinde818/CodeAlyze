#include<stdio.h>
#include<string.h>

int main()
{
  char s[101],t[101];
  char u;
  int n,m;
  int i,j;
  int a=0;
  scanf("%s",s);
  scanf("%s",t);
  n=strlen(s);
  m=strlen(t);
  for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
      if(s[i]>s[j]){
        u=s[i];
        s[i]=s[j];
        s[j]=u;
      }
    }
  }
  for (i=0;i<m;i++){
    for (j=i+1;j<m;j++){
      if(t[i]<t[j]){
        u=t[i];
        t[i]=t[j];
        t[j]=u;
      }
    }
  }
  for(i=0;i<n;i++){
    if(s[i]<t[i]){
      a=1;
      break;
    }
    if(s[i]>t[i]){
      a=2;
      break;
    }
  }
  if(a==0 && n<m) a=1;
  if(a==0 && n>=m) a=2;
  if(a==1) printf("Yes");
  if(a==2) printf("No");
  return 0;
}
