#include<stdio.h>
int main(void){
    int n,j,max,min;
    scanf("%d",&n);
    int a[n];
    for(j=0;j<n;j++){
        scanf("%d",&a[j]);
    }
    max=a[1]-a[0];
    min=a[0];
    for(j=1;j<n;j++){
    	 if(a[j]-min>max)
    max=a[j]-min;
        if(a[j]<min)
        min=a[j];
   
        
    }
    printf("%d\n",max);
    return 0;
}
