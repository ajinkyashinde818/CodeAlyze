#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,m; cin>>n>>m;
	string a[n],b[m];
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < m; i++) cin>>b[i];
	/*
	char a[n][n],b[m][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>a[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin>>b[i][j];
		}
	}
	*/
	for(int i = 0; i <= n-m; i++){
		for(int j = 0; j <= n-m; j++){
			int ac_num = 0;
			for(int h = 0; h < m; h++){
				for(int w = 0; w < m; w++){
					if(a[i+h][j+w] == b[h][w]){
						//cout<<"i = "<<i<<", j = "<<j<<", h = "<<h<<", w = "<<w<<endl;
						//cout<<"a[i+h][j+w] = "<<a[i+h][j+w]<<", b[h][w] = "<<b[h][w]<<endl;
						ac_num++;
					}
				}
			}
			if(ac_num == m*m){
				cout<<"Yes"<<endl;
				//cout<<"i = "<<i<<", j = "<<j<<endl;
				//cout<<"a[i] = "<<a[i]<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
