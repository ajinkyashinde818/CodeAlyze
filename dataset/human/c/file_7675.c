#include <stdio.h>
int main(){
    int date[10000],i=0,c=1;
    while(1){
        if(i>10000)break;
        scanf("%d",&date[i]);
        if(date[i]==0)break;
        i++;
    }
    i=0;
    while(1){
        if(date[i]==0)break;
        if(date[i]!=0){
            printf("Case %d: %d\n",c,date[i]);
            c++;
            i++;
        }
    }
    return 0;
}
