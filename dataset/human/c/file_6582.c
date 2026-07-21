#include <stdio.h>
int main(){
    int n,R,i;
    int max,min;
    
    scanf("%d",&n);
    scanf("%d",&min);
    scanf("%d",&R);
    max=R-min;
    
    if(R<min){
        min=R;
    }


    for(i=2;i<n;i++){
        scanf("%d",&R);
        if(R-min>max){
            max=R-min;
        }
        if(R<min){
            min=R;
        }
    }
    printf("%d\n",max);
    return 0;
}
