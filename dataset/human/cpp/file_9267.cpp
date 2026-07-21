#include <bits/stdc++.h>
using namespace std;


int n,m;
char a[55][55],b[55][55];

int main(){
	cin >> n >> m;
	for(int j=0;j<n;j++)for(int i=0;i<n;i++)cin>>a[j][i];
	for(int j=0;j<m;j++)for(int i=0;i<m;i++)cin>>b[j][i];
	
	bool exist=false;
	
	for(int dy=0;dy<n;dy++){
		for(int dx=0;dx<n;dx++){
			if(dx+m-1>=n or dy+m-1>=n)continue;
			
			bool match=true;
			for(int y=0;y<m;y++){
				for(int x=0;x<m;x++){
					if(a[dy+y][dx+x]!=b[y][x])match=false;
				}
			}
			if(match) exist=true;
		}
	}
	if(exist)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
