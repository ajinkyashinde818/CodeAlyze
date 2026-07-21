#include <stdio.h>
#include<math.h>
int main(void){
    int e,y;
    scanf("%d %d",&e,&y);
    if(e==0){
        if(y<=1911&&1868<=y){
            printf("M%d\n",y-1868+1);
        }
        if(y<=1925&&1912<=y){
            printf("T%d\n",y-1912+1);
        }
        if(y<=1988&&1926<=y){
            printf("S%d\n",y-1926+1);
        }
        if(y<=2016&&1989<=y){
            printf("H%d\n",y-1989+1);
        }
    }
        
    else if(e==1){
        printf("%d\n",1867+y);
    }

        
    else if(e==2){
        printf("%d\n",1911+y);
    }
        
    else if(e==3){
         printf("%d\n",1925+y);
    }
        
    else if(e==4){
        printf("%d\n",1988+y);
    }


    
    
    
    
}
