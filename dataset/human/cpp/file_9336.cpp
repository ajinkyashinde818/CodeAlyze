#include<bits/stdc++.h>
using namespace std;

string a[100],b[100];

int main(){
	int n,m,flag=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			flag=0;
			for(int st=i;st<(m+i);st++){
				for(int r=j;r<(m+j);r++){
					if(a[st][r]!=b[st-i][r-j])
						flag=1;
				}
			}
			if(flag==0){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
