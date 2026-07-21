// 20190427A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>

int main()
{
	/*int A, B, T;             A問題

	cin >> A >> B >> T;

	cout << T / A * B;*/

	//int N, i, v, c, max = 0;           //B問題
	//vector<int>V, C;

	//cin >> N;

	//for (i = 1; i <= N; i++) {
	//	cin >> v;
	//	V.push_back(v);
	//}

	//for (i = 1; i <= N; i++) {
	//	cin >> c;
	//	C.push_back(c);
	//}

	//for (i = 0; i < N; i++) {
	//	if (V[i] > C[i]) {
	//		max = max + V[i] - C[i];
	//	}
	//}

	//cout << max;


	/*int N, i, a;
	vector<int>A;

	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
	}

	int b, c;*/                 //C



	long long N, i, a;


	cin >> N;
	long long min, minus = 0;
	long long n = 0;
	for (i = 0; i < N; i++) {
		cin >> a;

		if (i == 0) {
			min = abs(a);
		}
		if (abs(a) < min) {
			min = abs(a);
		}
		if (a < 0) {
			minus++;
		}
		n += abs(a);
	}

	if (minus % 2 == 0) {

		cout << n;
	}
	else {

		cout << n - 2 * min;
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
