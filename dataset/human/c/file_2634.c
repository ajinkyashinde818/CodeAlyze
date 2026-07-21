#include <stdio.h>
 
int main()
{
  char a[4];
  scanf("%s",&a);
  int b[4] = {0,0,0};
  int i = 0;
  while (a[i])
  {
    if (a[i] == 'a')
      b[0] += 1;
    else if (a[i] == 'b')
      b[1] += 1;
    else
      b[2] += 1;
    i++;
  }
  if (b[0] == 1 && b[1] == 1 && b[2] == 1)
  	printf("Yes");
  else
    printf("No");
}
