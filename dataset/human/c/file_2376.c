#include<stdio.h>

int main(void){
  int i;
  char s[4];
  int a=0,b=0,c=0;
  
  scanf("%c%c%c",&s[0],&s[1],&s[2]);
  
  for(i=0;i<3;i++){
      if(s[i]=='a')
        a++;
      if(s[i]=='b')
        b++;
      if(s[i]=='c')
        c++;
  }
  
  if(a==1&&b==1&&c==1)
    printf("Yes\n");
  else 
    printf("No\n");
    
  return 0;
}
