#include<iostream>
#include<string>
#include<cmath>

using namespace std;


int main(){
	int R, G, B, N;
	int cnt = 0;
	int b=0;

	cin >> R >> G >> B >> N;
	

	for (int r = 0; r*R <= N; r++){
		for (int g = 0; g*G <= N - r*R; g++){

			if ((N - (r*R + g*G)) % B == 0){
				b = (N - (r*R + g*G)) / B;
			}

				if (r*R + g*G +b*B == N){
					cnt++;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}
