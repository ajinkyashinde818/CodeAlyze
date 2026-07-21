#include <bits/stdc++.h>

using namespace std;

int a[1003][1003];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int k=0;
	while(k*(k-1)<2*n) k++;
	if(k*(k-1)!=2*n){
		cout << "No";
		return 0;
	}else{
		cout << "Yes" << endl;
		cout << k << endl;
		int ind=1;
		for(int i=1;i<=k;i++){
			cout << k-1 << " ";
			int j;
			for(j=1;j<i;j++){
				a[i][j] = a[j][i];
				cout << a[j][i-1] << " ";
			}
			for(;j<=k-1;j++,ind++){
				a[i][j] = ind;
				cout << ind << " ";
			}
			cout << endl;
		}
	}
}
