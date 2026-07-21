#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M,ans;
	cin >> N >> M;
	vector<string> A(N), B(M);
	string comp;
	for (size_t i = 0; i < N; i++)//N*NのAをインプット
	{
		cin >> A.at(i);
	}
	for (size_t i = 0; i < M; i++)//M*MのBをインプット
	{
		cin >> B.at(i);
	}
	for (size_t i = 0; i <= N-M; i++)//(探索範囲は左上頂点のy座標がN-M-1となる場所まで)
	{
		for (size_t j = 0; j <= N-M; j++)//(x座標も同様)
		{
			ans = 1;
			for (size_t k = 0; k < M; k++)//完全一致でyes;
			{
				if (A.at(i+k).substr(j,M)!=B.at(k))//
				{
					ans = 0;
				}
			}
			if (ans == 1) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}
