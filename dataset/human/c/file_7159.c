#include<stdio.h>

int main(){
        int H,W;
        int h[10000],w[10000];
        int i,j,k,l;
        int a=20;

        for(i=0; ; i++){
                scanf("%d",&H);
                scanf("%d",&W);

                h[i] = H;
                w[i] = W;

                if((H == 0) && (W == 0)){
                        break;
                }
        }

        for(j=0; j<i; j++){
                for(k=0; k<h[j]; k++){
                        for(l=0; l<w[j]; l++){
                                if(a == 10){
                                        a = 0;
                                }
                                if(a == 20){
                                        a = 1;
                                }

                                if(a == 1){
                                        printf("#");
                                        a = 10;
                                        if(w[j]-1 == l && w[j] % 2 == 0){
                                                a = 20;
                                        }
                                }
                                if(a== 0){
                                        printf(".");
                                        a = 20;
                                        if(w[j]-1 == l && w[j] % 2 == 0){
                                                a = 10;
                                        }
                                }
                        }
                        printf("\n");
                }
                        printf("\n");
                        a = 20;
        }

        return 0;

}
