#include<stdio.h>
#include<string.h>
int main(){
  int i=0,n=0,m[3]={0,0,0},h,w;
  char s[4];
  scanf("%s",s);
  for(i=0;i<3;i++){
   if(s[i]=='a')
     m[0]=1;
   if(s[i]=='b')
     m[1]=1;
   if(s[i]=='c')
     m[2]=1;  
  }
  for(i=0;i<3;i++)
    if(m[i]==1)
      n++;
  if(n==3)
  printf("Yes");
  else
    printf("No");
  return 0; 
}
