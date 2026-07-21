#include <iostream>
using namespace std;

int main(){
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int n, cnt;
	cnt = 0;
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N-i; j++){
			n = N - i*R	- j*G;
			if(n >= 0 && n%B == 0){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
