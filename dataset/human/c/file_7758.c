#include <stdio.h>

int main(void){
    
    int i,x,y,z;
    
    scanf("%d", &z);
    
    for (i=1;i<=z;i++){
        scanf("%d", &x);
        scanf("%d", &y);
        
        if(x%y==0)
            printf("%d\n",y);
        else
            printf("%d\n",x%y);
    }
    
    return 0;
}
