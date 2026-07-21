#include<stdio.h>
#include<stdlib.h>
int main(){
  int a,i,j;
  int max,min;
  int *num;
  scanf("%d",&a);
  num=(int *)malloc(a * sizeof(int));
  for(i=0;i<a;i++){
    scanf("%d",&num[i]);
  }
  max=num[1]-num[0];
  min=num[0];
  for(j=1;j<a;j++){
    if(max>(num[j]-min))max=max;
    else if(max<(num[j]-min))max=num[j]-min;
    if(min<num[j])min=min;
    else if(min>num[j])min=num[j];
    }
  printf("%d\n",max);
  free(num);
  return 0;
}
