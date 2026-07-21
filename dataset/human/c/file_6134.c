#include<stdio.h>

int main(void){
    int n;
    int d1=0;
    int Rmin,R;
    
    scanf("%d",&n);
    scanf("%d",&Rmin);
    scanf("%d",&R);
    
    d1=R-Rmin;
    
    if(Rmin>R){
        Rmin=R;
    }
    
    for(int j=2;j<n;j++){
        scanf("%d",&R);
        if(d1<R-Rmin){
            d1=R-Rmin;
        }
        if(Rmin>R){
            Rmin=R;
        }
    }
    printf("%d\n",d1);
    
    return 0;
}
