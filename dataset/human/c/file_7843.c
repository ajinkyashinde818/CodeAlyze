#include <stdio.h>
#include <string.h>

#define N 1002
#define MAX 1000000

typedef struct {
	int x, y;
	int cost;
} QUEUE;

int main(void)
{
	int h, w, n;
	int i, j;
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	int qp = 0;			//	デキューする場所(最初)を指す
	int ep = 0;			//	エンキューする場所(最後)を指す
	int fp = 0;			//	find変数の添え字を指す
	int cost;							//	かかった歩数
	static char map[N][N];				//	マップ
	static char used[N][N];				//	通った点
	static char find[] = "123456789";	//	見つける文字
	static QUEUE que[MAX];
	
	memset(que, -1, sizeof(que));
	memset(used, 0, sizeof(used));
	
	scanf("%d%d%d", &h, &w, &n);
	
	for (i = 0; i < h; i++){
		scanf("%s", map[i]);
		
		for (j = 0; j < w; j++){
			if (map[i][j] == 'S'){
				map[i][j] = '.';
				que[qp].x = j;
				que[qp].y = i;
				que[qp].cost = 0;
				used[i][j] = 1;
				ep++;
			}
		}
	}
	while (qp != ep){
		
		//	デキュー
		int x = que[qp].x;
		int y = que[qp].y;
		cost = que[qp].cost;
		qp = (qp + 1) % MAX;
		
		//	チーズ（文字）見つけたら
		if (map[y][x] == find[fp]){
			fp++;
			
			//	すべてなら終了
			if (fp == n){
				break;
			}
			
			//	まだあるならリセット
			else {
				memset(used, 0, sizeof(used));
				memset(que, 0, sizeof(que));
				qp = 0;
				que[qp].x = x;
				que[qp].y = y;
				que[qp].cost = cost;
				ep = 1;
			}
		}
		else {
			//	次に進めるか確認
			for (i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				//	通ってなくて、壁でもないならエンキュー
				if (used[ny][nx] == 0 && map[ny][nx] != 'X'){
					if (nx >= 0 && nx < w && ny >= 0 && ny < h){
						que[ep].x = nx;
						que[ep].y = ny;
						que[ep].cost = cost + 1;
						used[ny][nx] = 1;
						ep = (ep + 1) % MAX;
					}
				}
			}
		}
	}
	printf("%d\n", cost);
	
	return (0);
}
