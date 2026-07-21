#include<stdio.h>
int main()
  { 
     int N,K,count=0,i;
     scanf("%d %d",&N,&K);
     int arr[N];
     for(i=0;i<N;i++)
       { 
         scanf("%d",&arr[i]);
       }
  for(i=0;i<N;i++)
    { 
      if(arr[i]>=K)
        { 
          count++;
        }
    }
  printf("%d",count);
  return 0;
  }
