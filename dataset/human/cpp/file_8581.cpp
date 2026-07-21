#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int N,M;
	vector<string> A,B;
	string s;
	cin >> N >> M;
	for(int i=0;i<N;++i){
		cin >> s;
		A.push_back(s);
	}
	for(int i=0;i<M;++i){
		cin >> s;
		B.push_back(s);
	}
	for(int i=0;i<=N-M;++i){
		int pos = A[i].find(B[0]);
		if(pos == string::npos) continue;
		bool match = true;
		for(int j=1;j<M;++j){
			if(A[i+j].substr(pos,M) != B[j]) {
				match = false;
				break;
			}
		}
		if(match == true) {cout << "Yes" << endl;return 0;}
	}
	cout << "No" << endl;
}
