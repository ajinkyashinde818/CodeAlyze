#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char a[n][n];
	char b[m][m];
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
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+m-1>=n||j+m-1>=n)continue;
			
			bool check=true;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(a[i+k][j+l]!=b[k][l])check=false;
				}
			}
			if(check==true){
				ans=true;
			}
		}
	}
	if(ans==true){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	
}
