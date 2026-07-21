#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;

int R, G, B, N;

int main(){
	cin >> R >> G >> B >> N;
	int res = 0;
	for(int i = 0; i * R <= N; i++){
		for(int j = 0; j * G <= N; j++){
			if((N - i * R - j * G) % B != 0) continue;
			if((N - i * R - j * G) / B >= 0) res++;
		}
	}
	cout << res << endl;
	return 0;
}
