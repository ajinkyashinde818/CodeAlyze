#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  	int a,b,c,n,i,j,k,count=0;
  	cin>>a>>b>>c>>n;
  	
  	for(i=0;i<=n/a;i++){
		for(j=0;j<=(n-i*a)/b;j++){
			if((n-i*a-j*b)%c==0){
              count++;
            }
        }
    }

	cout<<count<<endl;
}
