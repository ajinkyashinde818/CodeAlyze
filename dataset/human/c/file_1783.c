#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int a[n],b[n],c[n-1];
    int sum=0;
    for(int i=0;i<n;i++){
    
        scanf("%d",&a[i]);
    
    
    }
    for(int i=0;i<n;i++){
    
        scanf("%d",&b[i]);
    
    }
    for(int i=0;i<n-1;i++){
    
        scanf("%d",&c[i]);
    
    
    }
    int ant=1;
    sum=0;
    for(int i=0;i<n;i++){
        int j = a[i];
        
        
        sum+=b[j-1];
        if(j==ant+1 && i!=0)
            sum+=c[j-2];
        ant=j;
    }
    printf("%d",sum);
    return 0;
    
}
