//
//  main.cpp
//  comp
//
//  Created by ???????????? on 2017/11/08.
//  Copyright ?? 2017??´ ????????????. All rights reserved.
//

#include <stdio.h>

int main(void) {
   
    while(true)
    {
        
        int H,W;
        scanf("%d%d",&H,&W);
        
        if (H==0||W==0)
        {
            break;
        }
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                if ((i+j)%2==1){
                    printf(".");
                }
                else{
                    printf("#");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    
         return 0;
}
