#include <stdio.h>

int main(int argc, char *argv[]){
    
    int h[256], w[256];
    int i=0;
    
    while(1){
        scanf("%d %d", &h[i], &w[i]);
        if((h[i] == 0)&&(w[i] == 0)) break;
        i++;
    }
    
    for(int j=0; j<i; j++){
        for(int hei=0; hei<h[j]; hei++){
            for(int wid=0; wid<w[j]; wid++){
                if(hei%2==0){
                    if(wid%2==0) printf("#");
                    else printf(".");
                }
                else{
                    if(wid%2==0) printf(".");
                    else printf("#");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
