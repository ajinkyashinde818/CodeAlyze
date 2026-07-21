#include <iostream>
#include <vector>	// 配列	
#include <algorithm> // sort
#include <cstdlib>  // abs() for integer


using namespace std;

int main() {
	int N;

	cin >> N;

	std::vector<long long> card;

	long long inp = 0; // 入力値
	long long tot = 0; // 入力値の合計
	for (int i = 0; i < N; i++) {
		cin >> inp;

		// 配列に要素を追加
		card.push_back(inp);

		tot += inp; // 入力値を集計

		//// debug 002
		//cout << "inp:" << inp << endl;
		//cout << "card[i]:" << card[i] << endl;

	}

	
	long long snu = 0; // すぬけ
	long long ara = 0; // アライグマ
	std::vector<long> absary; // 絶対値の配列

	for (int j = 0; j < N - 1; j++) {
		
		// すぬけの集計
		snu += card[j];

		ara = tot - snu;
		//for (int k = j + 1; k < N; k++) {
		//	// アライグマの集計
		//	ara += card[k];
		//}
		
		//// debug 002
		//cout << "snu:" << snu << endl;
		//cout << "ara:" << ara << endl;

		long buf = abs(snu - ara);
		absary.push_back(buf);

	}



	// 配列のソート
	std::sort(absary.begin(), absary.end());

	cout << absary[0] << endl;
}
