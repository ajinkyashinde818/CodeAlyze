#include <stdio.h>
#define N 200000
int main()
{
  int num,a,arr[N],min,max;
  scanf("%d",&num);
  for(int i = 0; i < num ; i++){
    scanf("%d",&arr[i]);
    if(i == 0) continue;
    if(i ==1){
      min = arr[0];
      max = arr[1] - arr[0];
    }
    if(max < arr[i] - min) max = arr[i]-min;
    if(min > arr[i]) min = arr[i];
  }
  printf("%d\n",max);
}
