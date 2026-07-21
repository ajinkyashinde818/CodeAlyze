#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	vector<string> B(M);

	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < M; i++) cin >> B[i];

	int offset = N - M;
	bool found = false;
	for(int i = 0; i <= offset; i++){
		for(int j = 0; j <= offset; j++){
			bool same = true;
			int bx = 0;
			for(int x = i; x < i + M; x++, bx++){
				int by = 0;
				for(int y = j; y < j + M; y++, by++){
					// cout << A[y][x] << " " << B[by][bx] << endl;
					if(A[y][x] != B[by][bx]){
						same = false;
						break;
					}
				}
				if(!same) break;
			}
			if(same){
				found = true;
				break;
			}
		}
		if(found) break;
	}
	if(found) cout << "Yes" << endl;
	else cout << "No" << endl;
}
