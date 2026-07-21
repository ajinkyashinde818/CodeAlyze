#include <stdio.h>
 
int main(void) {
    int n,a=0,b=0,i,d1,d2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&d1,&d2);
        if(d1==d2){
            a=a+1;
            if(a==3){
                b=b+1;
            }
        }else{
            a=0;
        }
    }
    if(b>0){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
