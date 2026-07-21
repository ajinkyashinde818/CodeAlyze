#include<stdio.h>
int main(void){
    int n;
    int a[1000],b[1000],c[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);  
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);  
    }
     for(int i=0;i<n-1;i++){
        scanf("%d",&c[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=b[a[i]-1];
       // printf("%d\n",sum);
        //printf("%d %d\n",a[i],a[i-1]);
        if((a[i]-1)==a[i-1]){
            sum+=c[a[i]-2];
        }
    }
    printf("%d\n",sum);
    return 0;
}
