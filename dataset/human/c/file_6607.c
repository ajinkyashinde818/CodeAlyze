#include <stdio.h>
int main(void){
    int n,R,i,max_v,v;
    scanf("%d",&n);
    scanf("%d",&v);
    scanf("%d",&R);
    max_v=R-v;
    if(R<v)v=R;
    for(i=2;i<n;i++){
        scanf("%d",&R);
        if(R-v>max_v)max_v=R-v;
        if(R<v)v=R;
    }
    printf("%d\n",max_v);
    return 0;
}
