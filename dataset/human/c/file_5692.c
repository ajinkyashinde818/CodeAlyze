#include <stdio.h>

int main (){
    int i, j, t, n=0; 
    int R[10000000]={0};
    int maxv, minv;

    scanf("%d",&n);
    for(t=0; t<n; t++){
        scanf("%d",&R[t]);
    }
    
    maxv = (R[1] - R[0]);
    minv = R[0];
    for(j=1; j<n; j++){
        if(maxv < R[j]-minv) maxv = R[j]-minv;      //maxv = (maxv と R[j]-minv のうち大きい方)
        if(minv > R[j])      minv = R[j];           //minv = (minv と R[j] のうち小さい方)
        
        //printf("%d %d\n", maxv, minv);
    }

    printf("%d\n", maxv); 
    
return 0;
}
