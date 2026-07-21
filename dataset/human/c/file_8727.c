#include<stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  int a[N+1];
  for (int i = 1; i < N+1; i++)
  {
    scanf("%d",&a[i]);
  }

  int i=a[1],j=1,counter=1;
  while (i!=2&&j<N+1)
  {
    i=a[i];
    counter++;
    j++;
  }
  
  counter > N ? puts("-1"): printf("%d",counter);

  return 0;
}
