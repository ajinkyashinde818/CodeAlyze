/*
AizuOnline A1002
Title Extraordinary Grid I
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
//Global data section
int T;
int N;
char book[40001];
//
int count_cost()
{
  int jou,ge,h1,h2,i,ret,jlast,glast,jfirst,gfirst;
  
  jou=ge=0;

  if(book[0]=='Y')
    jou++;
  for(i=0;i<N-1;i++)
    if(book[2*i+1]=='Y'||book[2*i+2]=='Y')
      {
	jou++;
      }
  
  if(book[2*N-1]=='Y')
      {
	jou++;
      }
  
  //-----*--------
  if(book[2*N]=='Y')
    ge++;
  for(i=0;i<N-1;i++)
    if(book[2*N+2*i+1]=='Y'||book[2*N+2*i+2]=='Y')
      {
	ge++;

      }
  if(book[4*N-1]=='Y')
      {
	ge++;
      }
  //--*--
  jlast=0;glast=0;
  for(i=2*N-1;i>=0;i--)
    if(book[i]=='Y')
      { 
	jlast=i;
	break;
      }
  for(i=2*N-1;i>=0;i--)
    if(book[2*N+i]=='Y')
      {
	glast=i;
	break;
      }  
//--*--
  jfirst=2*N;gfirst=2*N;
  for(i=0;i<2*N;i++)
    if(book[i]=='Y')
      { 
	jfirst=i;
	break;
      }
  for(i=0;i<2*N;i++)
    if(book[2*N+i]=='Y')
      {
	gfirst=i;
	break;
      }

  ret=N+jou+ge+(((jou==0)&&ge)?2:0)+((jou&&ge&&(glast>jlast))?1:0);
  ret+=((jou&&ge&&(gfirst<jfirst))?1:0);
  //printf("%d %d %d %d %d %d :%d\n",jou,ge,jlast,glast,jfirst,gfirst,ret);
  return(ret);
}

main()
{
  int i;
  int cost;

  scanf("%d",&T);
  for(i=0;i<T;i++)
    {
      scanf("%d",&N);
      scanf("%s",book); 
      printf("%d\n",count_cost());
    }
return(0);
}
