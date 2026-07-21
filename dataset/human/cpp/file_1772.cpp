#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int e[m];
	int integer[n+1]={0};
	for(int i=0;i<m;i++){
		cin >> e[i];
	}
	for(int i=m-1;i>=0;i--){
		if(integer[e[i]]==0){
			cout << e[i] << endl;
			integer[e[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(integer[i]==0)
			cout << i << endl;
	}

}
