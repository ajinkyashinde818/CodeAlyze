#include<stdio.h>

int main(){

int N,D,X;
int ans=0,j=1;
scanf("%d",&N);
scanf("%d%d",&D,&X);
int A[N];
for (int i = 0; i < N; i++)
{
  scanf("%d",&A[i]);
}

for (int i = 0; i < N; i++)
{
  while (j*A[i]+1<=D)
  {
    ans++;
    j++;
  }
  j=1;
}

printf("%d",ans+X+N);

return 0;

}
