#include<stdio.h>

int main(void)
{
  int h,w,i,j,frag=1;
  scanf("%d %d",&h,&w);
  char s[51][51];
  for(i=0;i<h;i++)
    {
      scanf("%s",s[i]);
    }

  for(i=0;i<h;i++)
    {
      for(j=0;j<w;j++)
	{
	  if(s[i][j] == '#')
	    {
	      frag = 0;
	      if(i-1 >= 0 && s[i-1][j] == '#')
		{
		  frag = 1;
		}
	      if(i+1 < h && s[i+1][j] == '#')
		{
		  frag = 1;
		}
	      if(j-1 >= 0 && s[i][j-1] == '#')
		{
		  frag = 1;
		}
	      if(j+1 < w && s[i][j+1] == '#')
		{
		  frag = 1;
		}
	    }
	  if(frag == 0)
	    {
	      printf("No\n");
	      return 0;
	    }
	}
    }
  printf("Yes\n");
  return 0;
}
