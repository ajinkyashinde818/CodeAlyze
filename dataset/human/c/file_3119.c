#include<stdio.h>

int main(){
int K,N,max=0;
scanf("%d%d",&K,&N);

int A[N],dist[N];

for (int i = 0; i < N; i++)
{
  scanf("%d",&A[i]);
}

dist[N-1] = K - A[N-1] + A[0];
max = dist[N-1];

for (int i = 0; i < N-1; i++)
{
  dist[i] = A[i+1] - A[i];
  if (max<dist[i])
  {
    max = dist[i];
  }
}

printf("%d",K-max);
return 0;

}
