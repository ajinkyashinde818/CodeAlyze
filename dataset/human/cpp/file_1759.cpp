#include<iostream>
#include<algorithm>
using namespace std;
int n,m,z;
pair<int,int> a[200010];//last,num
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)a[i].first=-1,a[i].second=n-i;
	for(int i=0;i<m;i++){
		cin>>z;z--;
		a[z].first=i;
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)cout<<n-a[i].second+1<<endl;
	return 0;
}
