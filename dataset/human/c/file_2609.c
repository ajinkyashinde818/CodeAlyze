#include<stdio.h>

int main(void)
{
  char s[4];
  scanf("%s",s);
  
  int a=0,b=0,c=0;
  int i;
  for(i=0;i<3;i++){
    switch(s[i]){
      case 'a':
        a=1;
        break;
      case 'b':
        b=1;
        break;
      case 'c':
        c=1;
        break;
    }
  }
  
  if(a==1&&b==1&&c==1){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}
