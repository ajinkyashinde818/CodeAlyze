// 2011/03/04 Tazoe

#include <iostream>
using namespace std;

struct wall{
	int x;
	int y;
	int r;
};

bool saf_jdg(struct wall wal, int x1, int y1, int x2, int y2)
{
	if((x1-wal.x)*(x1-wal.x)+(y1-wal.y)*(y1-wal.y)<wal.r*wal.r
	 &&(x2-wal.x)*(x2-wal.x)+(y2-wal.y)*(y2-wal.y)<wal.r*wal.r)
		return false;

	int vx = x2-x1;
	int vy = y2-y1;
	int cx = wal.x-x1;
	int cy = wal.y-y1;

	int vc = vx*cx+vy*cy;

	int v2 = vx*vx+vy*vy;
	int c2 = cx*cx+cy*cy;
	int r2 = wal.r*wal.r;

	if(vc<0)
		if(c2<r2)
			return true;
		else
			return false;

	if(vc>v2){
		int dx = wal.x-x2;
		int dy = wal.y-y2;
		int d2 = dx*dx+dy*dy;
		if(d2<r2)
			return true;
		else
			return false;
	}

	if(c2*v2-vc*vc<=r2*v2)
		return true;
	else
		return false;
}

int main()
{
	while(true){
		int n;
		cin >> n;
		if(n==0)
			break;

		struct wall wal[100];
		for(int i=0; i<n; i++)
			cin >> wal[i].x >> wal[i].y >> wal[i].r;

		int m;
		cin >> m;

		for(int i=0; i<m; i++){
			int tx, ty, sx, sy;
			cin >> tx >> ty >> sx >> sy;

			bool saf_flg = false;
			for(int j=0; j<n; j++)
				if(saf_jdg(wal[j], tx, ty, sx, sy)){
					saf_flg = true;
					break;
				}

			if(saf_flg)
				cout << "Safe" << endl;
			else
				cout << "Danger" << endl;
		}
	}

	return 0;
}
