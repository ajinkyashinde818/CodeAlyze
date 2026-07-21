#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;	cin>>n>>m;
	char a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cin>>a[i][j];
	}

	char b[m][m];
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++)cin>>b[i][j];
	}

//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++)cout<<a[i][j];
//		cout<<endl;
//	}
//	
//	for(int i=0;i<m;i++){
//		for(int j=0;j<m;j++)cout<<b[i][j];
//		cout<<endl;
//	}

	string ans;
	for(int y=0;y<=n-m;y++){
		for(int x=0;x<=n-m;x++){
			// この二重ループで検索エリアの始点（左上）をセット

			ans="Yes";

			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					if(a[y+i][x+j]!=b[i][j]){
						ans="No";
					}
				}
			}

			if(ans=="Yes")break;
		}
		if(ans=="Yes")break;
	}

	cout<<ans<<endl;


	return 0;
}
