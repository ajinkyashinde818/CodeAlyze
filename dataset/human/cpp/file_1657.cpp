#include <bits/stdc++.h>
using namespace std;
int n,k,a[5000][5000];
int main(){
	cin>>n;
	for(int i=1;i*(i-1)/2<=n;i++){
		if(i*(i-1)/2==n){
			puts("Yes");
			k=i;
			cout<<k<<endl;
			break;
		}
	}
	if(!k){
		puts("No");
		return 0;
	}
	for(int i=1;i<=k-1;i++){
		for(int j=1;j<=i;j++){
			if(j==1){
				if(i==1)a[i][j]=1;
				else a[i][j]=a[i-1][i-1]+1;
			}
			else a[i][j]=a[i][j-1]+1;
		}
	}
	for(int i=1;i<=k;i++){
		cout<<k-1<<" ";
		if(i!=k){
			for(int j=1;j<=i;j++)cout<<a[i][j]<<" ";
			for(int j=i+1;j<=k-1;j++)cout<<a[j][i]<<" ";
		}
		else for(int i=1;i<=k-1;i++)cout<<a[i][i]<<" ";
		cout<<endl;
	}
	return 0;
}
