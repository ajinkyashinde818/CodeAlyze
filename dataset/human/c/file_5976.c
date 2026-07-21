#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int R[n];
    for(int i=0;i<n;i++){
        scanf("%d",&R[i]);
    }
    int max,min;
    max=-1000000000;
    min=R[0];
    for(int j=1;j<n;j++){
        if(R[j]-min>max) max=R[j]-min;
        else;
        
        if(R[j]<min) min=R[j];
        else;
        }
    printf("%d\n",max);
    return 0;
    
}
