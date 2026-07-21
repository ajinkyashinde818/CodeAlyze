#include <stdio.h>

int main(void)
{
  char ch0, ch1, ch2;
  
  scanf("%c%c%c", &ch0, &ch1, &ch2);
  
  if(ch0 == ch1)
    puts("No");
  else if(ch1 == ch2)
    puts("No");
  else if(ch0 == ch2)
    puts("No");
  else 
    puts("Yes");
  
  return 0;
}
