#include <stdio.h>

int main(void) {
  int i;
  char s[4];
  int flag=0;


  scanf("%s",s );

  for ( i = 0; i < 3; i++) {
    if (s[i]=='a') {
      flag=flag+1;
    }
    if (s[i]=='b') {
      flag=flag+10;
    }
    if (s[i]=='c') {
      flag=flag+100;
    }
  }
 

  if (flag==111) {
    printf("Yes");
  }
  else{
    printf("No");
  }




  return 0;
}
