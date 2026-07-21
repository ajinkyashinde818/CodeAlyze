#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	char map[100][100],tem[100][100];
	for(int i=0; i<100; i++) {
		for(int j=0; j<100; j++)map[i][j]=tem[i][j]='w';
	}
	for(int i=0; i<n; i++){
		cin>>s;
		for(int j=0; j<n; j++) map[i][j]=s[j];
	}
	for(int i=0; i<m; i++){
		cin>>s;
		for(int j=0; j<m; j++) tem[i][j]=s[j];
	}
	int ans=0;
	for(int i=0; i<=n-m; i++){
		for(int j=0; j<=n-m; j++){
			int c=0;
			for(int p=0; p<m; p++){
				for(int q=0; q<m; q++){
					if(map[i+p][j+q]==tem[p][q])c++;
				}
			}
			if(c==m*m)ans=1;
		}
	}
	if(ans)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
