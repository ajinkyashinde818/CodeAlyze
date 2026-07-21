#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char c[50][50];
	char d[50][50];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>d[i][j];
		}
	}
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			for(int o=0;o<m;o++){
				for(int p=0;p<m;p++){
					if(c[i+o][j+p]!=d[o][p])goto a;
				}
			}
			cout<<"Yes"<<endl;
			return 0;
			a:;
		}
	}
	cout<<"No"<<endl;
    return 0;
}
