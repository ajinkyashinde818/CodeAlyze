#include <stdio.h>

#define BOARD_WIDTH_MAX 5
#define BOARD_HEIGHT_MAX 10

#define DELETE_THRESHOLD 3

typedef struct {
	int W,H;
	int score;
	int board[BOARD_HEIGHT_MAX][BOARD_WIDTH_MAX];
} game_t;

int game_delete(game_t *game) {
	int deleted=0;
	int i,j,k;
	for(i=0;i<game->H;i++) {
		int cnt=1;
		for(j=1;j<=game->W;j++) {
			if(j>=game->W || game->board[i][j]!=game->board[i][j-1]) {
				if(cnt>=DELETE_THRESHOLD && game->board[i][j-1]>0) {
					game->score+=game->board[i][j-1]*cnt;
					for(k=j-cnt;k<j;k++)game->board[i][k]=0;
					deleted=1;
				}
				cnt=1;
			} else {
				cnt++;
			}
		}
	}
	return deleted;
}

void game_fall(game_t *game) {
	int i,j,k;
	for(i=game->H-1;i>0;i--) {
		for(j=0;j<game->W;j++) {
			if(game->board[i][j]==0) {
				for(k=i-1;k>=0 && game->board[k][j]==0;k--);
				if(k>=0) {
					game->board[i][j]=game->board[k][j];
					game->board[k][j]=0;
				}
			}
		}
	}
}

int main(void) {
	game_t game;
	game.W=5;
	while(scanf("%d",&game.H)==1 && game.H>0) {
		int i,j;
		for(i=0;i<game.H;i++) {
			for(j=0;j<game.W;j++) {
				if(scanf("%d",&game.board[i][j])!=1)return 1;
			}
		}
		game.score=0;
		while(game_delete(&game))game_fall(&game);
		printf("%d\n",game.score);
	}
	return 0;
}
