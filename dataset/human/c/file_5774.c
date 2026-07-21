#include<stdio.h>

int main(void){
    int n;
    int a[200000];
    
    scanf("%d",&n);
    
    scanf("%d",a);
    for(int i=1;i<n;i++){
        scanf("%d",a+i);
        a[i-1]=a[i]-a[i-1];
    }
    int y=a[0],z=a[0];
    for(int i=0;i<n-2;i++){
        if(z+a[i+1]>a[i+1]){
            z+=a[i+1];
        }else{
            z=a[i+1];
        }
        
        if(z>y){
            y=z;
        }
    }
    
    printf("%d\n",y);
    
    return 0;
    
}
