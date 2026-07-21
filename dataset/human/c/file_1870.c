#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int a[n],b[n],c[n-1];
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d", &b[i]);
    }for(i=0;i<n-1;i++){
        scanf("%d", &c[i]);
    }

    int sum=0;
    for(i=0;i<n;i++){
        sum += b[a[i]-1];
        if(i<n){
          if(a[i+1]-a[i]==1){
              sum += c[a[i]-1];
          }
        }

    }
    printf("%d\n",sum);
    return 0;
}
