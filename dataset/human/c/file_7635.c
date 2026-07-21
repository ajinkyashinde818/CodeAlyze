#include <stdio.h>
int main(){
    int data[10000],i,j;
    i=0;
    do{
        scanf("%d",&data[i]);
    }while(data[i++] != 0);
    for(j=0;j<i-1;j++){
        printf("Case %d: %d\n",j+1,data[j]);
    }
    return 0;
}
