#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef struct pair<ll,int> P;

int main() {
	int n,m;
	string a[50];
	string b[50];

	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<m;++i)cin>>b[i];
	bool flg;
	for(int i=0;i<n-m+1;++i){
		for(int j=0;j<n-m+1;++j){
			flg=true;
			for(int k=0;k<m;++k){
				for(int h=0;h<m;++h){
					if(a[i+k][j+h]!=b[k][h])flg=false;
				}
			}
			if(flg){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
