#include<stdio.h>

int main(){

int n,i,max,min;

int R[200000];
 
 

     scanf("%d",&n);

   for(i = 0; i < n; i++){

    scanf("%d",&R[i]);

}

   max = R[1]-R[0];
 
   min = R[0];

   for(i = 1; i < n; i++){

      if(max < R[i]-min){

       max = R[i]-min;

 }

   if(min > R[i]){

    min = R[i];

  }

}

  printf("%d\n",max);

    return 0;

}
