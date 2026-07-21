#include <stdio.h>
int main(){
    int r;
    int n;
    int i;
    int max,min;
    
    scanf("%d",&n);
    
    scanf("%d",&min);
    scanf("%d",&r);
    max=r-min;
    if(r<min)min=r;
    for(i=2;i<n;i++){
        scanf("%d",&r);
        if(r-min>max)max=r-min;
        if(r<min){
            min=r;
        }
    }
    printf("%d\n",max);
    return 0;
}
