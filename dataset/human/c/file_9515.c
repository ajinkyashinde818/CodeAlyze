#include<stdio.h>

int main(void)
{
  int n,d,x;
  scanf("%d%d%d",&n,&d,&x);

  int count = 0;
  int a=0;
  int b=0;
  for(int i=0; i<n; i++){
    scanf("%d",&a);
    for(int j=1; j<=d; j = 1+b*a){
      count ++;
      b++;
    }
   //   printf("%d\n",count);
    b=0;
  }

  printf("%d",count+x);

    return 0;

}
