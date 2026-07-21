#include <iostream>
#include <vector>

using namespace std;
vector<int> v[100010];
int main(){
	long long i,j,k,n;
	cin >> n;
	for(i=0;i<=n;i++){
		if(i*(i+1)/2==n){
			k = i;
			break;
		}
		if(i==n){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	cout << k+1 << endl;
	int x = 1;
	for(i=1;i<=k+1;i++){
		for(j=i;j<=k;j++){
			v[i].push_back(x);
			v[j+1].push_back(x);
			x++;
		}
	}
	for(i=1;i<=k+1;i++){
		cout << v[i].size() << " ";
		for(int j:v[i]){
			cout << j << " ";
		}
		cout << endl;
	}
}
