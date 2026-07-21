#include<stdio.h>
int main(void){
    int h,w,a[100];
    while(1){
        scanf("%d%d",&h,&w);
        if(h==0&&w==0){
            break;
        }
        else{
            for(a[1]=1;a[1]<=h;a[1]++){

                for(a[0]=1;a[0]<=w;a[0]++){
                    a[3]=a[0]%2;
                    a[2]=a[1]%2;
                    if(a[2]==1){
                        if(a[3]==1){
                            printf("#");
                            }
                        else{
                        printf(".");
                        }
                    }

                    else if(a[2]==0){
                        if(a[3]==1){
                            printf(".");
                            }
                        else{
                        printf("#");
                        }

                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }

        }
    return 0;
}
