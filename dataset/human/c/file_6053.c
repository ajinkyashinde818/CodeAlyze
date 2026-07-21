#include <stdio.h>
int main(int argc, const char * argv[])
{
    int count,max=-2000000000,min=2000000000,j,i;
    scanf("%d",&count);
    int x[count];
    for(i=0;i<count;i++){
       scanf("%d",&x[i]);
    }
    for(j=0;j<count;j++){
       if(max<x[j]-min){
           max=x[j]-min;
       }
       if(min>x[j]){
         min=x[j];
       }
    }
    printf("%d\n",max);
    return 0;
}
