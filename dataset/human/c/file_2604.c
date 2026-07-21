#include<stdio.h>
int main(){
  char s[]="abc",x[4];
  int i,a=0,b=0,c=0;
  scanf("%s",x);
  for(i=0;i<3;i++){
     if(s[0]==x[i])
       a++;
  	 if(s[1]==x[i])
       b++;
     if(s[2]==x[i])
       c++;
  }
  if(a==1&&b==1&&c==1)
   printf("Yes");
  else
   printf("No");
  return 0;
  }
