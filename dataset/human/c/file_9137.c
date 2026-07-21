#include <stdio.h>

int main(){
    int n,k,count;
    scanf("%d%d",&n,&k);
    count=0;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(k<=a[i]){

        count++;
        }
    
    }

    
    printf("%d",count);
    


    return 0;
}
