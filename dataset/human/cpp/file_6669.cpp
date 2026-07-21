#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int distsq(int x1, int y1, int x2, int y2){
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

// 線分と円の外周との当たり判定
bool checkLineCircle(int tx, int ty, int sx, int sy, int wx, int wy, int wr){
	bool t_in = (distsq(tx, ty, wx, wy) < wr*wr);
	bool s_in = (distsq(sx, sy, wx, wy) < wr*wr);
	if(t_in && s_in) return false; // お互いが中なら接触していない
	if(t_in != s_in) return true; // お互いの中/外が異なれば接触している

	// 線分の始点/終点が円の外部
	int vx = sx - tx; // 始点→終点 へのベクトル
	int vy = sy - ty;
	int cx = wx - tx; // 始点→円の中心 へのベクトル 
	int cy = wy - ty;
	int cv = vx*cx + vy*cy; // cvの内積
	int vv = vx*vx + vy*vy;
	int cc = cx*cx + cy*cy;
	if(cv < 0) return false; // 内積<0 -> 円の中心は線分の始点方向の外
	if(cv > vx*vx+vy*vy) return false; // |c・v|>|v・v| なら 円の中心は終点方向の外
	if( cc-cv*cv/vv <= wr*wr) return true; // c^2 - (c*cosθ)^2 < wr^2 なら接触
	return false;
}

int main(){
	int n, m;
	while(cin >> n, n){
		vector<int> wx(n), wy(n), wr(n);
		for(int i = 0; i < n; i++){
			cin >> wx[i] >> wy[i] >> wr[i];
		}
		cin >> m;

		int tx, ty, sx, sy;
		for(int i = 0; i < m; i++){
			cin >> tx >> ty >> sx >> sy;
			bool safe = false;
			for(int j = 0; j < n; j++){
				if(checkLineCircle(tx, ty, sx, sy, wx[j], wy[j], wr[j])){
					safe = true;
					break;
				}
			}
			if(safe) cout << "Safe" << endl;
			else cout << "Danger" << endl;
		}

	}

	return 0;
}
