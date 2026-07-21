#include "bits/stdc++.h"
using namespace std;
char a[50][51];
char b[50][51];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++) cin>>b[i][j];
	}

	bool exist = false;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+m-1>=n || j+m-1>=n) continue;

			bool match = true;
			for(int y=0;y<m;y++){
				for(int x=0;x<m;x++){
					if(a[i+y][j+x] != b[y][x]) match = false;
				}
			}
			if(match) exist = true;
		}
	}

	if(exist) printf("Yes\n");
	else printf("No\n");

	return 0;
}
