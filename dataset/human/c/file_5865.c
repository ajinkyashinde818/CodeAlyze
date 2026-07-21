#include<stdio.h>
#include<math.h>
int main(void){
    int minv,maxv,i,n,R[200000];

    maxv=-1.0E9;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&R[i]);
    }

    minv=R[0];
    for(i=1;i<n;i++){
        if(maxv<R[i]-minv){
            maxv=R[i]-minv;
        }
        if(R[i]<minv){
            minv=R[i];
        }
    }

    printf("%d\n",maxv);
    return 0;

}
