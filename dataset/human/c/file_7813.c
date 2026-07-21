#include <stdio.h>
int main(void){
    // Here your code !
    int N,Ki,Pi,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&Ki,&Pi);
        if(Ki%Pi == 0)printf("%d\n",Pi);
        else printf("%d\n",Ki%Pi);
    }
    return 0;
}
