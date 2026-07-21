#include<iostream>
#include<string>
using namespace std;

const int MAX = 50;
int main() {
	int N, M;
	cin >> N >> M;
	string A[MAX], B[MAX];
	for (int i = 0;i < N;i ++) cin >> A[i];
	for (int i = 0;i < M;i ++) cin >> B[i];
	
	for (int i = 0;i < N - M + 1;i ++) {
		for (int j = 0;j < N - M + 1;j ++) { // (i,j)から(i+M-1, j+M-1)までの範囲がBと一致するか調べる
			bool include = true;
			for (int k = i;k < i + M;k ++) {
				for (int l = j;l < j + M;l ++) {
					if (A[k][l] != B[k - i][l - j]) { // もしBと一致しない部分があったら
						include = false;
						k = i + M;
						break;
					}
				}
			}
			if (include) { // もしBがAに含まれていたら
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

実際にBが入る全ての座標において、Bと一致するかどうか判定してみる
その時のオーダーはO((N-M)^2・M^2)なのでまぁ間に合うか
*/
