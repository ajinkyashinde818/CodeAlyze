#include <stdio.h>
int main(int argc, const char * argv[]) {
    int R[200000];
    int i=0;
    int a;
    
    int maxv,min;
    scanf("%d",&a);
    while(i<a){
        scanf("%d",&R[i]);
        i++;
    }
    min=R[0];
    maxv=R[1]-R[0];
    for(i=1;i<a;i++){
        
        if((R[i]-min)>maxv){
            maxv=R[i]-min;
        }
        if(R[i]<min){
            min=R[i];
        }
                 }
    
    
    printf("%d\n",maxv);
    return 0;
}
