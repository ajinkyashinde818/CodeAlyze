#include <stdio.h>

int height;  /* 盤面の高さ */
int stone[10][5];  /* 石の並び */
int score;

/* 初期化し石の並びを入力する */
void input(int h){
	int x, y;
	height = h;
	for (y = h - 1; y >= 0; y--){
		for (x = 0; x < 5; x++){
			scanf("%d", &stone[y][x]);
		}
	}
	score = 0;
}

/* 石の並びを出力する */
void show(){
	int x, y;
	for (y = height - 1; y >= 0; y--){
		for (x = 0; x < 5; x++){
			if (x != 0) printf(" ");
			if (stone[y][x] != 0){
				printf("%d", stone[y][x]);
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("---------\n");  /* 底 */
}

/* 指定された石群を消滅させる (0 でセルを埋める) */
int delete(int y, int from, int to){
	int x, score = 0;
	for (x = from; x < to; x++){
		score += stone[y][x];
		stone[y][x] = 0;
	}
	return score;
}

/* 揃った石を消滅させ、コンボ数を返す */
int try(){
	int combo = 0, y;
	for (y = 0; y < height; y++) combo += tryLine(y);  /* 各行について判定する */
	return combo;
}

int tryLine(int y){
	int x, from, to;

	for (from = 0, to = 1; to <= 5; to++){
		if (to == 5 || stone[y][to] != stone[y][to-1]){
			/* 同じ石が3個以上並んでいるなら石が消滅する */
			if (to - from >= 3 && stone[y][to-1] != 0){
				score += delete(y, from, to);  /* from から to - 1 までの石を消しスコアを加算する */
				return 1;
			}
			/* 連続の左端を更新する */
			from = to;
		}
	}

	return 0;
}

/* 石を落として空きセルを埋める */
void drop(){
	int y, top, bottom;  /* 空きセルの上端 top, 下端 bottom */
	for (y = 0; y < 5; y++){
		for (bottom = 0, top = 0; top < height; top++){
			if (stone[top][y] != 0){
				/* 石を下まで落とす */
				if (top > bottom){
					stone[bottom][y] = stone[top][y];
					stone[top][y] = 0;
				}
				bottom++;
			}
		}
	}
}

int main(void){
	int h;
	while (scanf("%d", &h) == 1 && h >= 1 && h <= 10){
		input(h);
		/* show(); */
		while (try()){  /* 新たに消える石がなくなるまで繰り返す */
			drop();
			/* show(); */
		}
		printf("%d\n", score);  /* スコアを出力する */
	}
    return 0;
}
