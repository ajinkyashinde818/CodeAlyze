#include <stdio.h>

int main()
{
    int H[65535],W[65535];
    int i,j,k;
    
    for(i=0;;i++){
        scanf("%d %d",H+i,W+i);
        if(H[i]==0&&W[i]==0)
            break;
    }

    for(i=0;H[i]!=0||W[i]!=0;i++){
        for(j=0;j<H[i];j++){
            for(k=0;k<W[i];k++){
                if(j%2==0){
                    if(k%2==0){
                         printf("#");
                    }else{
                         printf(".");
                    }
                 }else if(k%2==0){
                     printf(".");
                 }else{
                     printf("#");
                 }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
