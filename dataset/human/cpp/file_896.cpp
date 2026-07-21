#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
	int R, G, B, n,x,y, ans = 0;
	cin >> R >> G >> B >> n;
	for (int i = 0; i<= n/R; i++){
		x = n - (R*i);
		for (int j = 0; j <= x / G;j++){
			y=x - G*j;
			if (y%B == 0){
				ans++;
			}
		}
	}
	cout << ans << endl;
}
