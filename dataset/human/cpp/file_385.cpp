#include <bits/stdc++.h>
using namespace std;

int main(void){
    int R, G, B, N, r, g, b, n;
	cin >> R >> G >> B >> N;
	g = 0;
	n = 0;
	int inter;
	for (int r = 0; r <= (N / R); r++){
        for (int g = 0; g <= (N - r * R) / G; g++){
			inter = N - R * r - G * g;
			if (inter % B == 0){
				b = inter / B;
				n++;
				continue;
			}else{
				continue;
			}
		}
	}
	cout << n << endl;
}
