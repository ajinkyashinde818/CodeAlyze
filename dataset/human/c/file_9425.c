#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
 
int main()
{
  long long N,D,X;
  int A[101] = {};
  int i,j;
  int number;
  char s[10];
  long long  cnt_c=0;
  long long  cnt=0;

//    int k=0;
  scanf("%lld ", &N);
  scanf("%lld %lld",  &D, &X);
  
  for(i=0;i<N;i++){
    scanf("%d ", &A[i]);
    cnt = ((D-1) / A[i]) + 1; 
//    printf("%lld\n",  cnt);
    cnt_c = cnt_c + cnt ;
  }
 //printf("%lld %lld %lld %lld", A, B, C, D);
//  scanf("%lld", &M);
    
  printf("%lld\n",(cnt_c + X));
//     printf("%c%c%c\n",s[0][0],s[1][1],s[2][2]);

return 0;
}
