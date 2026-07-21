#include <stdio.h>
int main(void){
    
    int i,n,a[100000],b;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    i=0; b=a[0];
    while(i<n){
        i++;
        if(b==2){
            printf("%d\n",i);
            return 0;
        }
        else{
            b=a[b-1];
        }
    }
    printf("-1\n");
    return 0;
}
