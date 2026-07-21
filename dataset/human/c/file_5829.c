#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    
    int min=-1000000000, max=1000000000, i;
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        
        if(i && x-max>min) min=x-max;
        if(max>x) max=x;
    }
    
    printf("%d\n",min);
    return 0;
}
