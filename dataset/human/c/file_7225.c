#include <stdio.h>
int main(){
        int h,w,i,j,k;
        while(1){
        scanf("%d %d", &h,&w);
        if(h == 0 && w == 0) break;
        for(j=0;j<h;j++){
                if(j % 2 == 0){
                        if(w % 2 == 0){
                                for(i=0;i<w/2;i++){
                                        printf("#.");
                                }
                                printf("\n");
                        }else if(w % 2 != 0){
                                for(i=0;i<(w-1)/2;i++){
                                        printf("#.");
                                }
                        printf("#\n");
                        }
                }else if(j % 2 != 0){
                        if(w % 2 == 0){
                                for(i=0;i<w/2;i++){
                                        printf(".#");
                                }
                                printf("\n");
                        }else if(w % 2 != 0){
                                for(i=0;i<(w-1)/2;i++){
                                        printf(".#");
                                }
                        printf(".\n");
                        }
                }
        }
        printf("\n");
        }
return 0;
}
