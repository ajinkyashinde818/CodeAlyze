#include<iostream>
#include<string>
using namespace std;
string A[105],B[105];
int n,m;
int main(){
	cin>>n>>m;
	int xb,x2,x3,x4;
	for(xb=0;xb<n;xb++) cin>>A[xb];
	for(xb=0;xb<m;xb++) cin>>B[xb];
	for(xb=0;xb<n;xb++){
		for(x2=0;x2<n;x2++){
			if(xb+m-1<n && x2+m-1<n){
				bool fail=0;
				for(x3=xb;!fail && x3<=xb+m-1;x3++){
					for(x4=x2;!fail && x4<=x2+m-1;x4++){
						if(A[x3][x4]!=B[x3-xb][x4-x2]) fail=1;
					}
				}
				if(!fail){
					cout<<"Yes\n";
					return 0;
				}
			}
		}
	}
	cout<<"No\n";
	return 0;
}
