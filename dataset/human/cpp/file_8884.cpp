#include<iostream>
using namespace std;
#include<vector>

int main(){
	int n,m;
	cin>>n>>m;
	vector<string> a(n);
	vector<string> b(m);
	
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<m;i++)cin>>b[i];
	
	int ans=1;
	for(int i = 0;i<n-m+1;i++){
		for(int l = 0;l<n-m+1;l++){
			ans=1;
			for(int j = 0;j<m;j++){
				for(int k = 0;k<m;k++){
					if(a[i+j][l+k]!=b[j][k]){
						ans=0;
					}
				}
			}
				if(ans==1){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
