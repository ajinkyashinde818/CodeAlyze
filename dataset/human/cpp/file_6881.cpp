#include<bits/stdc++.h>
using namespace std;
long long n, k=-1, j=1, a[200005], b[200005]; 
int main(){
       std::ios::sync_with_stdio(false);
	cin>>n;
	for(long long i=1; i<=n; i++)
	cin>>a[i];
	for(long long i=1; i<=n; i++)
	cin>>b[i];
	for(long long i=1; i<=n; i++){
		if(a[i]!=k) j=1;
		if(b[i]==a[i]){
		       for(; j<=n; j++)
		       if(b[j]!=a[i] && a[i]!=a[j]){
		              swap(b[i], b[j]);
		              break;
		       }
		       if(a[i]==b[i]){
		              cout<<"No"<<endl;
		              return 0;
		       }
		}
		k=a[i];
	}
	cout<<"Yes"<<endl;
	for(long long i=1; i<=n; i++)
	cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
