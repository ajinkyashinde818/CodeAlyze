#include <bits/stdc++.h>
using namespace std;

int main(){
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	int N = n;
	int counter = 0;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if((n-i*r-j*g)%b==0 && (n-i*r-j*g)>=0) counter++;
			
		}
	}
	cout << counter;
	
	
}
