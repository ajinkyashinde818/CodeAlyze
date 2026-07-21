#include<stdio.h>
  
int main(){
  int n, i, max, min;
  int a[200000];
 
  scanf("%d" ,&n);
   for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
   max = a[1] - a[0];
   min = a[0];
   for(i = 1; i < n; i++){
	scanf("%d", &a[i]);
         if(max < a[i] - min){
     max = a[i] - min;
   }
      if(min > a[i]){
     min = a[i];
   }
  }

    printf("%d\n" ,max);
 
 return 0;
}
