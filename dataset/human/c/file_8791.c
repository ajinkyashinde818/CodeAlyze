#include <stdio.h>
     
    int main(void){
    int H,W,i,j;
    char hoge[50];
    bool array[52][52]={0};
    scanf("%d",&H);
    scanf("%d",&W);
     
    for(i=0;i<H;i++){
    scanf("%s",&hoge);
    for(j=0;j<W;j++){
    if(hoge[j] == '#')array[i][j]=1;
    }
    }
     
    for(i=0;i<H;i++){
    for(j=0;j<W;j++){
    if(array[i][j]){
    if(array[i][j-1]
     ||array[i-1][j]                            ||array[i+1][j]
     ||array[i][j+1]){
    }else{
    printf("No");
    return 0;
    }
    }
    }
    }
    printf("Yes");
    return 0;
    }
