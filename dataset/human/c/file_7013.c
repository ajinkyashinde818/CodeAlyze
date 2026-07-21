#include<stdio.h>
int main(void){
        int a;
        int b;
        int n;
        for(n=1;n!=0;n=1){
            scanf("%d %d",&a,&b);
            if(a==0&&b==0){
                break;
            }
            else{
                n=b;
                for(a=a;a!=0;a--){
                    for(b=n;b!=0;b--){
                        printf("#");
                        b--;
                        if(b!=0){
                            printf(".");
                        }
                        else{
                            break;
                        }
                    }
                    printf("\n");
                    a--;
                    if(a!=0){
                        for(b=n;b!=0;b--){
                            printf(".");
                            b--;
                            if(b!=0){
                                printf("#");
                            }
                            else{
                                break;
                            }
                        }
                    }else{
                        break;
                    }
                    printf("\n");
                }
                printf("\n");       
            } 
        }       
        return 0;
}
