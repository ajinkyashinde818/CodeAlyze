#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n,m;
	string a[50],b[50];
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int k;
			for(k=0;k<m;k++){
				int l;
				for(l=0;l<m;l++){
					if(a[i+k][j+l]!=b[k][l]) break;
				}
				if(l!=m) break;
			}
			if(k==m){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
