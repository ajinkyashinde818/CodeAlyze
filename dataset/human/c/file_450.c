#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int r;
} WALL;

// 内積
#define dotProduct(x1, y1, x2, y2) (( x1 * x2 ) + ( y1 * y2 ))
// 円の中に点があるかどうか
#define inCircle(x1, y1, c) (pow(c.x - x1, 2) + pow(c.y - y1, 2) < c.r * c.r ? 1 : 0)

int judge(WALL w, int tx, int ty, int sx, int sy) {
    //V : 線分始点から終点へのベクトル
    //C : 線分始点から円中心へのベクトル
    int Vx = tx - sx;
    int Vy = ty - sy;
    int Cx = w.x - sx;
    int Cy = w.y - sy;
    int n1, n2, n3;

    int in_t = inCircle(tx, ty, w);
    int in_s = inCircle(sx, sy, w);

    if (in_t && in_s)
	return 0;

    if (in_t || in_s)
	return 1;

    //二つのベクトルの内積を求める
    n1 = dotProduct(Vx, Vy, Cx, Cy);
    n2 = dotProduct(Vx, Vy, Vx, Vy);
    n3 = dotProduct(Cx, Cy, Cx, Cy);

    if (n1 < 0 || n1 > n2) 
	return 0;
    return (n3 - (n1 * n1 / n2) <= pow(w.r, 2)) ? 1 : 0;
}




int main(void) {
    int n;

    while (scanf("%d", &n), n) {
	int i, m;
        WALL w[100];
        for (i = 0; i < n; i++) {
	    scanf("%d%d%d", &w[i].x, &w[i].y, &w[i].r);
	}
	scanf("%d", &m);
        for(i=0; i < m; i++){
            int j, safe = 0;
            int tx, ty, sx, sy;
            scanf("%d%d%d%d", &tx, &ty, &sx, &sy);
 
            for(j = 0 ; j < n; j++)
                if (judge(w[j], tx, ty, sx, sy) == 1) {
                    safe = 1;
                    break;
                }
 
            if (safe)
                printf("Safe\n");
            else
                printf("Danger\n");
        }
    }
 
    return 0;
}
