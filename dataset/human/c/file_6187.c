#include<stdio.h>

int main(void){
   int n,i,j,min,max,R[10000000];
   scanf("%d",&n);
   
   for(i=0;i<n;i++)
       scanf("%d",&R[i]);
       
       min=R[0];
       max=R[1]-R[0];
       
   for(j=1;j<n;j++){
   if(max<=R[j]-min)
      max=R[j]-min;
   
      if(min>R[j])
          min=R[j];
}

printf("%d\n",max);

return 0;
}
