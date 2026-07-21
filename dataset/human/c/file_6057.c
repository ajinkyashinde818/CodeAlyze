#include<stdio.h>
#include<math.h>

int main(){
  int i,R,n,min,max=-(pow(10,9));

  scanf("%d",&n);
  //R=(int *)malloc(sizeof(int)*n);

  scanf("%d",&min);
  max=max-min;
  for(i=1;i<n;i++){
    scanf("%d",&R);
    if(max<R-min) max=R-min;
    if(min>R){
      min=R;
      // printf("min:%d\n",min);
    }
  }
  printf("%d\n",max);
  return 0;
}
