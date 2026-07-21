/*
  AOJ 2583
  Title:JAG-channel
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

char line[1000][51];
char prefix[1001];
int  prefix_len;
int  level[1000];
int  last_brother[1000];
int n;

void read_line(char line[],int * lev)
{
  int i;

  char buf[1051];
  scanf("%s",buf);
  i=0;
  while(buf[i]=='.')
    i++;
  *lev=i;
  strcpy(line,&buf[i]);
}
void check_last_brother(int line)
{
  int i,lv,elder_brother;

  elder_brother = -1;
  
  for(i=line+1,lv=level[line];i<n && level[i]>lv;i++)
    {
      if(i>n || level[i]<=lv)
	return;
      if(level[i]==lv+1)
	{
	  if(elder_brother>=0)
	    {
	      last_brother[elder_brother]=-1;
	    }
	  check_last_brother(i);
	  elder_brother=i;
	}
    }
}
void    print_result()
{
  int i,j;
  
  printf("%s\n",line[0]);

  prefix_len=0;
  for(i=1;i<n;i++)
    {
      if(level[i]==level[i-1]+1)
	{
	  if(last_brother[i-1]==0 && prefix_len>0)
	    prefix[prefix_len-1]=' ';  
	  prefix[prefix_len]='|';  
	  prefix_len++;
	}
      else
	prefix_len=level[i];

      for(j=0;j<prefix_len-1;j++)
	printf("%c",prefix[j]);
      printf("+%s\n",line[i]);
    }
}
clear()
{
  memset(line,0,1000*51);
  memset(level,0,1000*sizeof(int));
  memset(last_brother,0,1000*sizeof(int));
}
main()
{
  int i;
  while(scanf("%d",&n) && n)
    {
      clear();
      for(i=0;i<n;i++)
	read_line(&line[i][0],&level[i]);

      check_last_brother(0);
      print_result();
    }
  return(0);
}
