#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
int compare_int(const void *a, const void *b)
{
    return *(long long*)a - *(long long*)b;
}

int min_comp(int min, int a)
{

}
int max_comp(int max, int a)
{
  if(max>a)    return max;
  else    return a;
}

int double_num(int num, int time)
{
if(time>=1){
    time = time - 1;
    num = num * 2;
    num = double_num(num, time);
     return num;
  }
if(time<=0) return num;
 }

int main()
{
  //int A, B, C, X, Y;
//  int m[101]={};
  long long min=0;
  int A, B, C, K;
  char s[51][51]={{},{}};
  int i,j;
  long long cnt=0;
  long long max=0;
  long long ca=0;
  int point_a=1;
  int point_b=1;
  int point_c=1;
  int flag=0;  
//    int k=0;

  scanf("%d %d ", &A ,&B);
  //printf("%d\n", A);
  for(i=0;i<B;i++){
      scanf("%s", &s[i]);
}
  for(i=0;i<B;i++){
 //     scanf("%s", &s[i]);
    for(j=0;j<A;j++){

       if(s[i][j] == '#'){
        flag=0;
        if((s[i+1][j] == '#') || (s[i][j+1] == '#') ){
          flag=1;
        }
        if(i>=1){
          if(s[i-1][j] == '#'){
            flag=1;
          }
        }
        if(j>=1){
          if(s[i][j-1] == '#'){
            flag=1;
          }
        }
       if(flag==0){
         printf("No\n"); 
         return 0;
       }
//       printf("%c" ,s[i][j]);
   }
  }
}
 printf("Yes\n"); 
return 0;
}
