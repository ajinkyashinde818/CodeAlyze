#include <stdio.h>

int main (){
    int n,i,x[200000],max,min;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    max=x[1]-x[0];
    min=x[0];
    for(i=1;i<n;i++){
        if(max<x[i]-min){
            max=x[i]-min;
        }
        if(min>x[i]){
            min=x[i];
        }  
    }
    printf("%d\n",max);
    return 0;
}
