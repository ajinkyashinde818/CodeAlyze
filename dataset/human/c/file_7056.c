#include <stdio.h>

int main(int argc, const char * argv[]){
    int h[1000],w[1000],num=0; //??????,??????,?????°
    int i,x,y; //???????????¨
    
    while(1){
        
        scanf("%d %d",&h[num],&w[num]);
        if(h[num]==0 && w[num]==0){
            break;
        }
        
        if(h[num]<1 || 300<h[num] || w[num]<1 || 300<w[num]){
            num--;
        }
        num++;
    }
    
    for(i=0; i<num; i++) {
        for(y=0; y<h[i]; y++) {
            for(x=0; x<w[i]; x++) {
                
                if(y%2!=0){
                    if(x%2!=0){
                        printf("#");
                    }
                    else{printf(".");}
                }
                if(y%2==0){
                    if(x%2!=0){
                        printf(".");
                    }
                    else{printf("#");}
                }
                
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
