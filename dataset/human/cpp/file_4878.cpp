#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main()
{
	int N, R; // 参加回数、表示レーティング
	cin >> N >> R;

	int answer; // 内部レーティング

	if (N > 9) 
	{
		answer = R; // 等しい
	}
	else 
	{
		answer = R + 100 * (10 - N); // R == answer - 100 * (10 - N) <=> answer = R + 100 * (10 - N) 
	}

	cout << answer << endl;

	return 0;
}
