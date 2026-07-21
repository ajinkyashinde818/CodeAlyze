#include <stdio.h>

int main()
{
  char s[3];
  int a = 0, b = 0, c = 0;

  scanf("%s\n", s);
  
  if(s[0] == 'a') a++;
  if(s[0] == 'b') b++;
  if(s[0] == 'c') c++;

  if(s[1] == 'a') a++;
  if(s[1] == 'b') b++;
  if(s[1] == 'c') c++;

  if(s[2] == 'a') a++;
  if(s[2] == 'b') b++;
  if(s[2] == 'c') c++;

  if(a == 1 && b == 1 && c == 1) {
    printf("Yes\n");
  }
  else {
    printf("No\n");
  }
  return 0;
}
