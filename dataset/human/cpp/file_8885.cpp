#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][n];
	int b[m][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
				char x;
				cin>>x;
				if(x=='#')
					a[i][j]=0;
				else
					a[i][j]=1;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
				char x;
				cin>>x;
				if(x=='#')
					b[i][j]=0;
				else
					b[i][j]=1;
		}
	}
	int count=0;
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			count=0;
			for(int k=i;k<i+m;k++){
				for(int l=j;k<j+m;l++){
					if(a[k][l]==b[k-i][l-j])
						count++;
					else{
						break;
						count=0;
					}
					if(count==m*m){
						cout<<"Yes";
						return 0;
					}
				}
				if(count==0) break;
			}
		}
	}
	cout<<"No";
}
