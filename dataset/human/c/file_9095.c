#include <stdio.h>
int main()
{
	int N,K;
    scanf("%d",&N);
    scanf("%d",&K);
    int data[N];
  int cnt=0;
  for(int i=0;i<N;i++)
  {
  	scanf("%d",&data[i]);
    if(data[i]>=K) cnt++;
    
  }
  printf("%d",cnt);
}
