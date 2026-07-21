#include <stdio.h>
#define N 200003
int main(void){
    int n,i,a[N],max=-222220,min;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    max=a[1]-a[0];
    min=a[0];
    for(i=1;i<n;i++){
        if(min>a[i]){
            min=a[i];
            continue;
        }
        if(a[i]<=a[i+1])
            continue;
        if(a[i]-min>max)
            max=a[i]-min;
    }
    
    
    printf("%d\n",max);
    return 0;
}
