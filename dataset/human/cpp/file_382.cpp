#include <bits/stdc++.h>
using namespace std;

int main(){
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	
	int sum = 0;
	for(int i = 0; i*R <= N; i++)
		for(int j = 0; i*R+j*G <= N; j++){
			int v = i*R+j*G;
			if((N-v)%B == 0)
				sum++;		
		}

	cout << sum << endl;
}
