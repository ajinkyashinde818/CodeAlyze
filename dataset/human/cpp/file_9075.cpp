#include<bits/stdc++.h>

using namespace std;

const int N = 55;
int n,m;
char a[N][N],b[N][N];

bool check(int u,int v){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]!=a[u+i-1][v+j-1])
				return false;
		}
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a,'1',sizeof(a));
    memset(b,'2',sizeof(b));
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cin >> a[i][j];
		}
	}
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=m;j++){
    		cin >> b[i][j];
		}
	}
	
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(a[i][j]==b[1][1] && i+m<=n+1 && j+m<=n+1){
    			if(check(i,j)){
    				cout << "Yes" << "\n";
    				return 0;
				}
			}
		}
	}
    cout << "No" << "\n";
    
	return 0;
}
