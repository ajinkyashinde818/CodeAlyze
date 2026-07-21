#include <iostream>
#include <vector>
using namespace std;
int N;
int main(){
	cin >> N;
	bool judge = false;
	int count = 0;
	vector<vector<int>> v(100010);
	for(int i=0;i*(i-1)/2<=N;i++){
		if(i*(i-1)/2==N){
			judge = true;
			count = i;
		}
	}
	if(!judge){
		cout << "No" << endl;
		return 0;
	}
	int c = 1;
	for(int i=1;i<count;i++){
		for(int j=i+1;j<=count;j++){
			v[i].push_back(c);
			v[j].push_back(c);
			c++;
		}
	}
	cout << "Yes" << endl;
	cout << count << endl;
	for(int i=1;i<=count;i++){
		cout << v[i].size() << " ";
		for(int j=0;j<v[i].size();j++){
			cout << v[i][j] << (j!=v[i].size()-1? " ":"\n");
		}
	}
}
