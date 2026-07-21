#include<stdio.h>

int main(){
    int n,t,R[200000],j,i;
    scanf("%d",&n);
    for(t=0;t<n;t++){
        scanf("%d",&R[t]);
    }
    
    int min=R[0];
    int max=R[1]-R[0];
    
    for(i=1;i<n;i++){
        if(max<(R[i]-min)) max=R[i]-min;
        if(min>R[i]) min=R[i];
    }
    printf("%d\n",max);
    return 0;
}
