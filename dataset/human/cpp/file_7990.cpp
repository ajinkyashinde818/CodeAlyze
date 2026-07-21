#include<iostream>	// 入出力
#include<stdio.h>	// printf()が使える小数は%fで
#include<math.h>	// 数学の関数
#include<vector>	// 配列
#include<string>	// 文字列
#include<map>		// 連想配列
#include<stack>		// スタック
#include<queue>		// キュー
#include<algorithm> // ソートとか

using namespace std;



int main()
{
	int N; cin >> N;

	vector<long long int> a(N);

	long long int sub = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		sub += a[i];
	}

	long long int ans = abs(sub);

	for (int i = 0; i < N-1; ++i)
	{
		sub -= 2 * a[i];


		if (ans > abs(sub)||i==0) { ans = abs(sub); }
	}

	cout << ans << endl;

	return 0;
}
