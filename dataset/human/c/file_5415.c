// Aizu 0214: Autumnal Illumination
// 2017.9.10 bal4u@uu

#include <stdio.h>

#define MAX 102

/* UNION-FIND library */
int p[MAX], rank[MAX];
void make_set(int x) { p[x] = x, rank[x] = 0; }
void link(int x, int y) {
	if (rank[x] > rank[y]) p[y] = x;
	else { p[x] = y; if (rank[x] == rank[y]) rank[y] = rank[y] + 1;	}
}
int find_set(int x) { if (x != p[x]) p[x] = find_set(p[x]);	return p[x]; }
void union_set(int x, int y) { link(find_set(x), find_set(y)); }

typedef struct { int x[4], y[4]; } T;
T tbl[102];

int isPointonSegment(int x, int y, int x1, int y1, int x2, int y2)
{
    int d;
    if (x1 > x2) d = x1, x1 = x2, x2 = d;
    if (y1 > y2) d = y1, y1 = y2, y2 = d;
    return (x1 <= x && x <= x2 && y1 <= y && y <= y2 && (y-y1)*(x2-x1) == (y2-y1)*(x-x1));
}

int crossSegments(int x11, int y11, int x12, int y12,
                  int x21, int y21, int x22, int y22)
{
    int s11, s12, s21, s22;
    int r = 0;

    s11 = (x22-x21) * (y11-y21) + (y22-y21) * (x21-x11);
    s12 = (x22-x21) * (y12-y21) + (y22-y21) * (x21-x12);
    s21 = (x12-x11) * (y21-y11) + (y12-y11) * (x11-x21);
    s22 = (x12-x11) * (y22-y11) + (y12-y11) * (x11-x22);
    if      (!s11) { if (!r) r = isPointonSegment(x11, y11, x21, y21, x22, y22); }
    else if (!s12) { if (!r) r = isPointonSegment(x12, y12, x21, y21, x22, y22); }
    else if (!s21) { if (!r) r = isPointonSegment(x21, y21, x11, y11, x12, y12); }
    else if (!s22) { if (!r) r = isPointonSegment(x22, y22, x11, y11, x12, y12); }
    else r = ((s11 <= 0 && s12 >= 0) || (s11 >= 0 && s12 <= 0)) &&
             ((s21 <= 0 && s22 >= 0) || (s21 >= 0 && s22 <= 0));
    return r;
}

int insidePolygon(int x, int y, int *xx, int *yy)
{
	int i, j, k;
	int sa, sb;

	k = 0;
	for (i = 1, j = 2; j < 4; i++, j++) {
	    sa = (xx[i]-xx[k]) * (y    -yy[k]) + (yy[i]-yy[k]) * (xx[k]-x    );
		sb = (xx[i]-xx[k]) * (yy[j]-yy[k]) + (yy[i]-yy[k]) * (xx[k]-xx[j]);
		if (sa*sb <= 0) continue;

		sa = (xx[j]-xx[i]) * (y    -yy[i]) + (yy[j]-yy[i]) * (xx[i]-x    );
		sb = (xx[j]-xx[i]) * (yy[k]-yy[i]) + (yy[j]-yy[i]) * (xx[i]-xx[k]);
		if (sa*sb <= 0) continue;

	    sa = (xx[k]-xx[j]) * (y    -yy[j]) + (yy[k]-yy[j]) * (xx[j]-x    );
		sb = (xx[k]-xx[j]) * (yy[i]-yy[j]) + (yy[k]-yy[j]) * (xx[j]-xx[i]);
		if (sa*sb <= 0) continue;
	    return 1;
	}
	return 0;
}

int together(int a, int b)
{
	int ia, ja, ib, jb;

	for (ia = 0; ia < 4; ia++) {
		ja = ia + 1; if (ja == 4) ja = 0;
		for (ib = 0; ib < 4; ib++) {
			jb = ib + 1; if (jb == 4) jb = 0;
			if (crossSegments(tbl[a].x[ia], tbl[a].y[ia], tbl[a].x[ja], tbl[a].y[ja],
                tbl[b].x[ib], tbl[b].y[ib], tbl[b].x[jb], tbl[b].y[jb])) return 1;
		}
	}
	for (ia = 0; ia < 4; ia++) {
		if (insidePolygon(tbl[a].x[ia], tbl[a].y[ia], tbl[b].x, tbl[b].y)) return 1;
	}
	for (ib = 0; ib < 4; ib++) {
		if (insidePolygon(tbl[b].x[ib], tbl[b].y[ib], tbl[a].x, tbl[a].y)) return 1;
	}
	return 0;
}

int main()
{
	int m, n, i, j, ans;

	while (scanf("%d", &n) && n) while (n-- > 0) {
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			for (j = 0; j < 4; j++) scanf("%d%d", &tbl[i].x[j], &tbl[i].y[j]);
			make_set(i);
		}
		if (m == 1) { puts("1"); continue; }
		for (i = 0; i < m; i++) for (j = i+1; j < m; j++)
			if (together(i, j)) union_set(i, j);
		for (ans = i = 0; i < m; i++) if (p[i] == i) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
