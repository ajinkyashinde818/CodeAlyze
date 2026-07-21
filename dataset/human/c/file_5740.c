#include <stdio.h>
#include <math.h>
   
int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    int min = pow(10, 9);
    int max_prof = -pow(10, 9);
    for (int i=0; i<n; i++){
      scanf("%d", &a[i]);
      if((i!=0) && (a[i]-min)>max_prof){
        max_prof = a[i] - min;
      }
      if(a[i]<min){
         min = a[i];
      }
    }
    printf("%d\n", max_prof);
    return 0;
}
