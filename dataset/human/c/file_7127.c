#include <stdio.h>

int main()
{
    int h,w;
    int i,k,f=0;

    while(1){
        scanf("%d %d",&h,&w);
        if( h==0 && w==0 ){
            return 0;
        }
        for(i=0;i<h;i++){
            for(k=0;k<w;k++){
                if( f%2== 0 ){
                    printf("#");
                    f++;
                }
                else{
                    printf(".");
                    f=0;
                }
            }
            if((k%2)==0){
              f++;
            }
            printf("\n");
        }
        f=0;
        printf("\n");

    }

    return 0;


}
