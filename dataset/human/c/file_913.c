/*
AizuOnline A2331
A Way to Invite Friends
13/01/08
*/
#define DEBUGx 1
#include <stdio.h>
// Select Below
//#include <stdlib.h>
#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
#define min(x,y) (((x)<(y))?(x):(y))
//Global data section
int N;
int a[100000];
int b[100000];
int ab[200000]; // merge A+B
//
// desc
int comp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}
int search_run(int ** ar,int num,int * limit)
{
  int i=0;
  while(**ar == num && *ar < limit)
    {
      *ar=*ar+1;
      i++;
    }
  return(i);
}
print()
{
  int i;
  printf("a:");
  for(i=0;i<N;i++)
    printf("%d ",a[i]);
  printf("\nb:");
  for(i=0;i<N;i++)
    printf("%d ",b[i]);
  printf("\nab:");
  for(i=0;i<N*2;i++)
    printf("%d ",ab[i]);
  printf("\n");
}
main()
{
  int s,i,j,nin,w1,w2;

  int *pa,*pb,*pab,**ppa,**ppb,**ppab;

  
  if(EOF != scanf("%d",&N))
    {
      for(i=0;i<N;i++)
	{
	  scanf("%d %d",&(a[i]),&(b[i]));
	}
      //print();
      memmove(ab,a,N*sizeof(int));
      memmove(ab+N,b,N*sizeof(int));

      qsort(a,N,sizeof(int),comp);
      qsort(b,N,sizeof(int),comp);
      qsort(ab,2*N,sizeof(int),comp);
#ifdef DEBUG
      print();
#endif
      if(N == 1)
	{
	  if(a[0] <= 2 && b[0] > 1)
	    printf("%d\n",1);
	  else
	    printf("%d\n",0);
	  goto END;
	}
      /*
      if(a[n-1] < N && b[0] > N)
	{
	  
	}
      */
      s=ab[0];
      nin=0;pa=a;pb=b;pab=ab;ppa=&pa;ppb=&pb;ppab=&pab;
      while(*ppa < pa +N && *ppb < pb + N && *ppab < pab+2*N && s)
	{
	  w1=search_run(ppb,s,a+N);
	  w2=search_run(ppa,s,a+N);
	  nin += w1;
#ifdef DEBUG
	  printf("s:%d nin:%d w1:%d w2:%d \n",s,nin,w1,w2);	  
#endif
	  if(nin+1 >= s)
	    {	    
	      printf("%d\n",s-1); //except me 
	      goto END;
	    }
	  if(nin == N && a[0] < N)     // call all friends
	    {	    
	      printf("%d\n",N);  
	      goto END;
	    }
	  nin -= w2;
	  search_run(ppab,s,ab+2*N);
	  s = **ppab;
	}
    }
    printf("%d\n",0);
 END:
return(0);
}
