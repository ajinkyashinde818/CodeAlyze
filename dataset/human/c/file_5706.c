#include <stdio.h>
int main(){
    int n,temp,bot,top=0,nb;
    scanf("%d",&n);
    scanf("%d",&bot);
    nb=bot;
    for(int i=1;i<n;i++){
        scanf("%d",&temp);
        if(temp-nb>top-bot){
            bot=nb;
            top=temp;
        }
        else if(temp>top)top=temp;
        if(temp<nb)nb=temp;
    }
    printf("%d\n",top-bot);
}
