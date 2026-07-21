#include<stdio.h>

int main(){
    int H, W;
    int mas[100][100];
    char s[100];
    int i,j,k;
    int ans = 0, sum;

    for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            mas[i][j] == 0;
        }
    }

    scanf("%d %d", &H, &W);

    for(i=0; i<H; i++){
        scanf("%s", &s);
        for(j=0; j<W; j++){
            if(s[j] == '#'){
                mas[i+1][j+1] = 1;
            }
            //printf("%d ",mas[i+1][j+1]);
        }
        //printf("\n");
    }

    for(i=1; i<=H; i++){
        for(j=1; j<=W; j++){
            if(mas[i][j] == 1){
                sum = mas[i-1][j] + mas[i+1][j] 
                      + mas[i][j-1] + mas[i][j+1];
                if(sum == 0){
                    ans =1;
                }
            }
        }
    }

    if(ans == 0){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}
