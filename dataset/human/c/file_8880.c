#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(void){
    int height,width;
    char **cell;

    scanf("%d %d",&height,&width);
    cell=(char **)malloc(sizeof(char *)*(height));
    int i;
    for(i=0;i<height;i++){
        cell[i]=(char *)malloc(sizeof(char)*width);
    }
    int j;
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            scanf(" %c",&cell[i][j]);
        }
    }
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(i==0){
                if(j==0){
                    if(cell[i][j]=='#'){
                        if(cell[i+1][j]!='#'&&cell[i][j+1]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
                else if(j!=0&&j!=width-1){
                    if(cell[i][j]=='#'){
                        if(cell[i+1][j]!='#'&&cell[i][j-1]!='#'&&cell[i][j+1]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
                else if(j==width-1){
                    if(cell[i][j]=='#'){
                        if(cell[i+1][j]!='#'&&cell[i][j-1]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
            }
            else if(i!=0&&i!=height-1){
                if(j==0){
                    if(cell[i][j]=='#'){
                        if(cell[i+1][j]!='#'&&cell[i][j+1]!='#'&&cell[i-1][j]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
                else if(j!=0&&j!=width-1){
                    if(cell[i][j]=='#'){
                        if(cell[i+1][j]!='#'&&cell[i-1][j]!='#'&&cell[i][j-1]!='#'&&cell[i][j+1]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
                else if(j=width-1){
                    if(cell[i][j]=='#'){
                        if(cell[i+1][j]!='#'&&cell[i-1][j]!='#'&&cell[i][j-1]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
            }
            else if(i==height){
                if(j==0){
                    if(cell[i][j]=='#'){
                        if(cell[i][j+1]!='#'&&cell[i-1][j]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
                else if(j!=0&&j!=width-1){
                    if(cell[i][j]=='#'){
                        if(cell[i-1][j]!='#'&&cell[i][j-1]!='#'&&cell[i][j+1]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
                else if(j=width-1){
                    if(cell[i][j]=='#'){
                        if(cell[i-1][j]!='#'&&cell[i][j-1]!='#'){
                            printf("No");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Yes");
    free(cell);
    return 0;
}
