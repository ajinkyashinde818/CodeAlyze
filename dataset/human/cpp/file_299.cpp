#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int R, G, B, N;
  	cin >> R >> G >> B >> N;
  	int Rmax = N / R;
  	int Gmax = N / G;
  	int cnt = 0;
  	for (int r = 0; r <= Rmax; r++){
    	for (int g = 0; g <= Gmax; g++){
    		int rest = N - r * R - g * G;
          	if (rest >= 0 && rest % B == 0){
            	cnt++;
            }
    	}
    }
  	cout << cnt << endl;
}
