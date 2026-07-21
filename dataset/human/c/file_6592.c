#include<stdio.h>
#include<stdlib.h>

int main(){
  int *data, cnt, min_data, max=-1000000000, i;

  //input data number
  scanf("%d",&cnt);
  data=(int *)malloc(cnt*sizeof(int));
  for(i=0;i<cnt;i++)scanf("%d",&data[i]);

  //judge
  min_data=data[0];
  for(i=1;i<cnt;i++){
    if(max<data[i]-min_data) max=data[i]-min_data;
    if(min_data>data[i]) min_data=data[i];
  }

  //output max value
  printf("%d\n",max);

  free(data);
  return 0;
}
