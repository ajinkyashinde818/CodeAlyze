#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for(int i=0;i<n;++i) cin >> a[i];
	for(int i=0;i<m;++i) cin >> b[i];
	
	bool exist=false;
	for(int ly=0;ly<n;++ly){
		for(int lx=0;lx<n;++lx)
		{
			if(ly+m-1>=n or lx+m-1>=n) continue;
			bool match = true;
			for(int y=0;y<m;++y){
				for(int x=0;x<m;++x)
				{
					if(a[ly+y][lx+x]!=b[y][x]) match=false;
				}
			}
			if(match) exist=true;
		}
	}
	if(exist) cout << "Yes" << endl;
	else cout << "No" << endl;
		
	return 0;
}
