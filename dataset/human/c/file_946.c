#include <stdio.h>
int main(){
    int e,y;
    scanf("%d%d",&e,&y);
    if(e==0){
        if(y>1988)printf("H%d",y-1988);
        else if(y>1925)printf("S%d",y-1925);
        else if(y>1911)printf("T%d",y-1911);
        else printf("M%d",y-1867);
        printf("\n");
        return 0;
    }
    else if(e==1)y+=1867;
    else if(e==2)y+=1911;
    else if(e==3)y+=1925;
    else y+=1988;
    printf("%d\n",y);
}
