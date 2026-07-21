#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int i = 1;
	while(N > i*(i+1)/2){
		i++;
	}
	int k = i+1;
	int ans[k][k-1];
	int num = 1;
	int b;
	if(N == (k*(k-1)/2)){
		cout << "Yes" << endl;
        cout << k << endl;
		for(int a=0;a<k;a++){
			cout << k-1;
			for(b=0;b<a;b++){
				ans[a][b] = ans[b][a-1];
				cout << " " << ans[a][b];
			}	
			while(b<k-1){
				ans[a][b] = num;
				cout << " " << ans[a][b];
				num++;
				b++;
			}
			cout << endl;
		}	
	}else{
		cout << "No" << endl;
	}
	return 0;
}
