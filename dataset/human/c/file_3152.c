#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int cmpnum(const void * n1, const void * n2)
{
	if (*(long *)n1 > *(long *)n2)
	{
		return 1;
	}
	else if (*(long *)n1 < *(long *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


int main(){
  long long K, N, maxa;
  long long a[2*100000],b[2*100000];

  scanf("%lld%lld",&K, &N);


  for (int i = 0; i < N; i++)
  {
      scanf("%lld", a + i);
  }

  qsort(a, N, sizeof(long long), cmpnum);

  b[0] = K + a[0] - a[N-1];  
  for (int i = 1; i < N; i++)
  {
      b[i] = a[i] - a[i-1];
  }  

  maxa = 0;

for (int i = 0; i < N; i++)
  {
      maxa = maxa < b[i] ? b[i] : maxa;
  }  

  
   printf("%lld\n", K-maxa);
  

  return 0;
}
