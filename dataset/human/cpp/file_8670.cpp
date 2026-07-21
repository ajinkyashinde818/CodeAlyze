#include <iostream>

using namespace std;
int N, M;
char A[51][51], B[51][51];
bool valid(int offX, int offY) {
	for (int y=0; y<M; y++) {
		for (int x=0; x<M; x++) {
			if (A[offX+x][offY+y] != B[x][y] ) {
				return false;
			}
		}
	}
	return true;
}

int main(){
	cin >> N >> M;
	for (int y=0; y<N; ++y) {
		for (int x=0; x<N; x++) {
			cin >> A[x][y];
		}
	}
	for (int y=0; y<M; ++y) {
		for (int x=0; x<M; x++) {
			cin >> B[x][y];
		}
	}
	
	for (int offY=0; offY<=N-M; offY++) {
		for (int offX=0; offX<=N-M; offX++) {

			if (valid(offX, offY)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
