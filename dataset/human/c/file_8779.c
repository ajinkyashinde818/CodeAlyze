#include <stdio.h>
typedef long long ll;
int H,W;

char board[52][52]; //0とH,Wの列はsentinel
int main(void){
    // Your code here!
    scanf("%d %d",&H,&W);
    char line[53];
    
    for(int y = 0; y <= H+1; y++){
        board[0][y] = board[W+1][y] = '.';
    }
    for(int x = 0; x <= W+1; x++){
        board[x][0] = board[x][H+1] = '.';
    }
    for(int y = 1; y <= H; y++){
        scanf("%s",line);
        for(int x = 1; x <= W; x++){
            board[x][y] = line[x-1];
        }
    }
    /*
    for(int y = 0; y <= H+1; y++){
        for(int x = 0; x <= W+1; x++){
            printf("%c",board[x][y]);
        }
        puts("");
    }*/
    for(int x = 1; x <= W; x++){
        for(int y = 1; y <= H; y++){
            if( board[x][y] == '#' &&
                board[x+1][y] == '.' && board[x-1][y] == '.'
             && board[x][y+1] == '.' && board[x][y-1] == '.'){
                puts("No");     
                             
                return 0;
             }
        }
    }
    puts("Yes");
}
