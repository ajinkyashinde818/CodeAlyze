#include<stdio.h>
 
char matrix[50][50];

int h,w;

int pos_correct(int i, int j){
    return i>=0 && i < h && j>=0 && j < w;
}


int dir_x[4] = {-1, 0, 0, 1};
int dir_y[4] = {0, -1, 1, 0};

int check(int i, int j){
    int k,count = 0;
    for(k = 0; k < 4; k++){
        if(pos_correct(i+dir_x[k], j+dir_y[k]))
            count += matrix[i+dir_x[k]][j+dir_y[k]] == '#';
            
    }
    return count != 0;
}



int main(){
    int i, j, i0, j0;
    char c;
    scanf("%d %d",&h, &w);
    scanf("%c",&c);
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            scanf("%c", &matrix[i][j]);
        }
        scanf("%c",&c);
    }

    int ans = 1;
    for(i = 0; i < h && ans; i++){
        for(j = 0; j < w; j++){
            if(matrix[i][j]=='#' && !check(i, j)){
                ans = 0;
                break;
            }
        }
    }


    if(ans)
        printf("Yes\n");
    else printf("No\n");


}
