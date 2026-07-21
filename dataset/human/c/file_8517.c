/* 
   AOJ 1193
   Chain Disappearance Puzzle
*/

#include<stdio.h>
#include<string.h>
#define HEIGHT_MAX 10
#define WIDTH 5
#define CONSECUTIVE 3
int board[HEIGHT_MAX][WIDTH];

int is_consecutive(int h)
{
  int i, prev = board[h][0], cnt = 1, max = 0, consecutive_num = 0, st = 0;
  for(i = 1; i < WIDTH; i++)
    {
      if(prev == board[h][i] && prev != 0)
	{
	  cnt++;
	  if(max <= cnt)
	    {
	      max = cnt;
	      consecutive_num = prev;
	    }
	}
      else
	{
	  if(max >= CONSECUTIVE)
	    {
	      break;
	    }
	  st = i;
	  cnt = 1;
	  prev = board[h][i];
	}
    }
  if(max >= CONSECUTIVE)
    {
      return max * 100 + consecutive_num * 10 + st;
    }
  else
    {
      return 0;
    }
}

void erase_stones(int h, int start_point, int end_point)
{
  int i, j;
  for(i = h; i >= 0; i--)
    {
      if(i == 0)
	{
	  for(j = start_point; j < end_point; j++)
	    {
	      board[0][j] = 0;
	    }
	}
      else
	{
	  for(j = start_point; j < end_point; j++)
	    {
	      board[i][j] = board[i - 1][j];
	    }	  
	}
    }
}

int main(void)
{
  int height, points = 0, i, j, cnt = 0, sp = 0, consecutive_n = 0, erase_flag = 0;
  int erase_line[HEIGHT_MAX] = {0};
  while(1)
    {
      points = 0;
      memset(board, 0, sizeof(board));
      scanf("%d", &height);
      if(!height)break;
      for(i = 0; i < height; i++)
	{
	  scanf("%d%d%d%d%d", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4]);
	}
      while(1)
	{
	  erase_flag = 0;
	  memset(erase_line, 0, sizeof(erase_line));
	  for(i = 0; i < height; i++)
	    {
	      erase_line[i] = is_consecutive(i);
	    }
	  for(i = 0; i < height; i++)
	    {
	      if(erase_line[i])
		{
		  cnt = erase_line[i] / 100, consecutive_n = (erase_line[i] % 100) / 10, sp = erase_line[i] % 10;
		  points += cnt * consecutive_n;
		  erase_stones(i, sp, sp + cnt);
		  erase_flag = 1;
		}
	    }
	  if(!erase_flag)break;
	}
      printf("%d\n", points);
    }
  return 0;
}
