#include<stdio.h>

int main()
{
 int N;
 int first;
 int second;
 
 scanf("%d",&N);
 first = N/10;
 second = N - first*10;

 if((first==9)|(second==9))
 {
  printf("Yes\n");
 }else{
  printf("No\n");
 }

return 0;
}
