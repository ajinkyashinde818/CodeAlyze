/*
AizuOnline A2340
Title Carpenter
*/
#include <stdio.h>
//Global data section
int q;
int p,n;
char c;
long long s;
//
main()
{
  int i;

  scanf("%d ",&q);
  s=0;
  for(i=0;i<q;i++)
    {
      scanf("%d %c %d",&p,&c,&n);
      if(c=='(')
	s += n;
      else
	s -= n;
      printf("%s\n",(s==0)?"Yes":"No");
    }
return(0);
}
