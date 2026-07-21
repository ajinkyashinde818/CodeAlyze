#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(void){
    int redbox,greenbox,bluebox;
    int sum;
    int numred,numgreen,numblue;
    int num_group=0;

    scanf("%d %d %d %d",&redbox,&greenbox,&bluebox,&sum);
    int i,j;
    for(i=0;i<=(sum/redbox)+1;i++){
        for(j=0;j<=(sum/greenbox)+1;j++){
            if(((sum-(redbox*i)-(greenbox*j))/bluebox)>=0){
                if((sum-(redbox*i)-(greenbox*j))%bluebox==0){
                    num_group++;
                    //printf("(%d,%d,%d)\n",i,j,(sum-(redbox*i)-(greenbox*j))/bluebox);
                }
            }
        }
    }
    printf("%d",num_group);
    return 0;
}
