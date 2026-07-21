#include <stdio.h>
#include <math.h>

int main(void){
        int k,n;
        scanf("%d %d",&k,&n);
        int a[k];
        for(int i=0; i<n; i++){
                scanf("%d",&a[i]);
        }
        int max=a[1]-a[0];
        for(int i=2; i<n; i++){
                max=fmax(max,a[i]-a[i-1]);
        }
        max=fmax(max,a[0]-a[n-1]+k);
        printf("%d\n",k-max);

        return 0;
}
