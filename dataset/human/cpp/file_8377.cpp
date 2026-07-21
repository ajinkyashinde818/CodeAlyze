#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char a[55][55],b[55][55];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
		}
	}
	bool ans=false;
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			bool ok=true;
			for(int f=0;f<m;f++){
				for(int g=0;g<m;g++){
					if(a[f+i][g+j]!=b[f][g])ok=false;
				}
			}
			if(ok){
				ans=true;
				break;
			}
		}
	}
	cout<<(ans?"Yes":"No")<<endl;
	return 0;
}
