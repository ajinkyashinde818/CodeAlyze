#include<stdio.h>

int main(void){

    int box[3],N,i,j,k,tmp,result = 0;

    for(i = 0;i < 3;i++){
        scanf("%d",&box[i]);
    }
    scanf("%d",&N);

    for(i = 0;i < 3;i++){
        for(j = i + 1;j < 3;j++){
            if(box[i] > box[j]){
                tmp = box[i];
                box[i] = box[j];
                box[j] = tmp;
            }
        }
    }

    //printf("並び替え後:%d %d %d\n",box[2],box[1],box[0]);

    for(i = 0;i <= N;i++){
        for(j = 0;j <= N;j++){
            k = (N - i * box[2] - j * box[1])/box[0];
            if(i * box[2] + j * box[1] + k * box[0] == N && k >= 0){
                //printf("(%d %d %d)\n",i,j,k);
                result++;
            }
        }
    }

    printf("%d\n",result);
    return 0;
}
