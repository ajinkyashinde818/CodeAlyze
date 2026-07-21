#include <stdio.h>

void init_array(int num[],int n)
{
  for(int i=0; i<n; i++)
    num[i] = -1;
}

long check(int n,int m,long x,long a[n][m+1],int num[n])
{
  long sum = 0,p;
  
  for(int i=1; i<=m; i++){
    p = 0;
    for(int j=0; j<n; j++){
      if(num[j] == -1)
        break;
      p += a[num[j]][i];
    }
     if(p < x)
       return -1;
  }

  for(int i=0; i<n; i++){
    if(num[i] == -1)
      break;
    sum += a[num[i]][0];
  }
  return sum;
}

int main(void)
{
  int n,m;
  long x,min = -1,sum;
  
  scanf("%d %d %ld",&n,&m,&x);
  
  long a[n][m+1];
  
  for(int i=0; i<n; i++)
    for(int j=0; j<=m; j++)
      scanf("%ld",&a[i][j]);
  
  for(int i=0; i<(1<<n); i++){
    int num[n];
    init_array(num,n);
    int k = 0;
    for(int j=0; j<n; j++){
      if((i >> j) & 1)
        num[k++] = j;
    }
    
    sum = check(n,m,x,a,num);
  
  if(min == -1)
    min = sum;
  else if(sum != -1 && min > sum)
    min = sum;
  }
  
  printf("%ld\n",min);
        
  return 0;
}
