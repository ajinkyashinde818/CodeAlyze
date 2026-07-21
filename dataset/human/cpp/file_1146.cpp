#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	int cnt=0;
	for(int i=0;i<=n/a;i++){
		for(int j=0;j<=n/b;j++){
			int k=n-(i*a)-(j*b);
			if(k%c==0&&k>=0)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
