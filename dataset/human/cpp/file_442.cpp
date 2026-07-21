#include <iostream>

using namespace std;
int main(){
	int i,j,r,g,b,n;
	cin >> r >> g >> b >> n;
	long long cnt = 0;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(r*i + g*j>n) break;
			if((n - r*i - g*j)%b==0){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
