//第8回シンデレラガール総選挙は是非本田未央ちゃんに投票をお願いします！
//ファンのことも他のアイドルの子たちのことも本当に大事にしてて、今まで周りに色んなものを与えてくれました。
//今度は私たちが未央ちゃんにお返しをする番です。みんなでガラスの靴を履かせてあげましょう！
// #本田未央を一番星に #本田未央を令和のシンデレラガールに #第8回シンデレラガール総選挙
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
int main()
{
	int r,g,b,n,out=0;
	cin>>r>>g>>b>>n;
	rep(i,n/r+1) rep(j,n/g+1){
		int x=n-i*r-j*g;
		if(x>=0 && x%b==0) out++;
	}
	cout<<out<<endl;
}
