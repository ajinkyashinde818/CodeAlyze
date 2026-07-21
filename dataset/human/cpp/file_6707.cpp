#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Wall { int x, y, r; };

bool inside(Wall w, double x, double y) {
	return w.r * w.r >= (w.x - x) * (w.x - x) + (w.y - y) * (w.y - y);
}

int main() {
	int n, wx, wy, r, m, tx, ty, sx, sy;
	while (cin >> n, n) {
		vector<Wall> w;
		for (int i=0; i<n; ++i) {
			cin >> wx >> wy >> r;
			w.push_back((Wall){wx, wy, r});
		}
		cin >> m;
		for (int i=0; i<m; ++i) {
			cin >> tx >> ty >> sx >> sy;
			bool safe = false;
			for (int j=0; j<n && !safe; ++j) {
				int k = inside(w[j], tx, ty) + inside(w[j], sx, sy);
				if (k == 0) {
					double dx, dy, x, y, minx, maxx, miny, maxy;
					dx = (sx - tx) / 10000.0;
					dy = (sy - ty) / 10000.0;
					x = tx;
					y = ty;
					minx = min(sx, tx);
					maxx = max(sx, tx);
					miny = min(sy, ty);
					maxy = max(sy, ty);
					while ( ! safe && minx <= x && x <= maxx && miny <= y && y <= maxy) {
						if (inside(w[j], x, y)) {
							safe = true;
							break;
						}
						x += dx;
						y += dy;
					}
				} else if (k == 1) {
					safe = true;
				}
			}
			cout << (safe ? "Safe" : "Danger") << endl;
		}
	}
	return 0;
}
