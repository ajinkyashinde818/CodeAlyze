#include<stdio.h>
int main(void){
    int loop,n;
    scanf("%d",&n);
    int r[n];
    for(loop=0;loop<n;++loop){
        scanf("%d",&r[loop]);
    }
    int min=r[0];
    int max=r[1]-r[0];
    for(loop=1;loop<n;++loop){
        if(max<r[loop]-min){
            max=r[loop]-min;
        }
        if(min>r[loop]){
            min=r[loop];
        }
    }
    printf("%d\n",max);
    return 0;
}
