#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	int R,G,B,N;

	cin >> R >> G >> B >> N ;

	int ans = 0;
	int rlim = N/R;
	int glim = N/G;

	for (int r = 0; r<= rlim; r++){
		for (int g = 0; g <= glim; g++){
			if (N >= r*R+g*G){
				if ( (N-(r*R+g*G)) % B == 0  ){
					ans += 1;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
