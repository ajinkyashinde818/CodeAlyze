#include <stdio.h>
int main(void)
{
  char p,q,r;
  int a=0,b=0,c=0;
  scanf("%s%s%s",&p,&q,&r);
  switch(p)
  {
    case 'a':
      a++;
      break;
    case 'b':
      b++;
      break;
    case 'c':
      c++;
      break;
  }
  switch(q)
  {
    case 'a':
      a++;
      break;
    case 'b':
      b++;
      break;
    case 'c':
      c++;
      break;
  }
  switch(r)
  {
    case 'a':
      a++;
      break;
    case 'b':
      b++;
      break;
    case 'c':
      c++;
      break;
  }
  if (a==1&&b==1&&c==1) printf("Yes\n");
  else printf("No\n");
}
