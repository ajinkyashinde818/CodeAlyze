#include <stdio.h>
#include <string.h>
int main()
{
  int H, W;
  int map[52][52];
  char b;
  int ok = 1;
  memset(map,0,sizeof(int)*52*52);
  scanf("%d%d%*c",&H,&W);
  for(int i = 1; i < H+1; i++)
    {
      for (int j = 1; j < W+1; j++)
	{
	  scanf("%c",&b);
	  if(b == '#')
	    {
	      map[i][j] = 1;
	    }
	  else
	    {
	      map[i][j] = 0;
	    }
	}
      scanf("%*c");
    }
  for(int i = 1; i < H+1; i++)
    {
      for(int j = 1; j < W+1; j++)
	{
	  if(map[i][j])
	    {
	      if(!(map[i-1][j] + map[i+1][j] + map[i][j-1] + map[i][j+1]))
		{
		  ok = 0;
		}
	    }
	}
      printf("\n");
    }
  if(ok)
    {
      printf("Yes\n");
    }
  else
    {
      printf("No\n");
    }
  return 0;
}
