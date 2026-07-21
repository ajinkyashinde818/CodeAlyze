#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<fstream>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);


//変数
LL N, C;
vector<pair<LL,LL>> xv;






//サブ関数
//入力
void input()
{
	cin >> N >> C;
	REP(i, N) {
		LL a, b;
		cin >> a >> b;
		xv.push_back({ a,b });
	}
}


//計算
void calc()
{
	vector<LL> nor1(1,0), nor2(1,0), rev1(1,0), rev2(1,0);

	//前計算
	REP(i, N) {
		nor1.push_back(nor1.back() + xv[i].second);;
		nor2.push_back(nor2.back() + xv[i].second);
		rev1.push_back(rev1.back() + xv[N - i - 1].second);
		rev2.push_back(rev2.back() + xv[N - i - 1].second);
	}
	REP(i, N) {
		nor1[i+1] -= xv[i].first;
		nor2[i+1] -= xv[i].first * 2;
		rev1[i+1] -= (C - xv[N - i - 1].first);
		rev2[i+1] -= (C - xv[N - i - 1].first) * 2;
	}
	vector<LL> imosNor(1,0), imosRev(1,0);
	REP(i, N) {
		imosNor.push_back(max(imosNor.back(), nor1[i + 1]));
		imosRev.push_back(max(imosRev.back(), rev1[i + 1]));
	}

	//測定
	//R→L
	LL ans = 0;
	REP(i, N + 1) {
		LL tmpS = rev2[i];
		tmpS += imosNor[nor1.size() - i-1];
		ans = max(ans, tmpS);
	}
	
	//L→R
	REP(i, N + 1) {
		LL tmpS = nor2[i];
		tmpS += imosRev[rev1.size() - i-1];
		ans = max(ans, tmpS);
	}

	cout << max(ans,0ll) << endl;
}


//出力
void output()
{

}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
