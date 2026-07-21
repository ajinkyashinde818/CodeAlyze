#include<stdio.h>
int main(void){
    int i,n,max,min,x;
    int a[200000];
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
 
    for(i=1;i<n;i++){
        if(i==1){
            max = a[1]-a[0];
            min = a[0];
        }
        x = a[i]-min;
        if(x>max)max = x;
        if(a[i]<min)min=a[i];
    }
    printf("%d\n", max);
    return 0;
}
