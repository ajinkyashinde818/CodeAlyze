#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int> > times;
int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		times.push_back({i, 0});
	}

	for(int j = 1; j <= M; j++){
		int a,b;
		cin >> a;
		times[a - 1].second = j;
	}

	sort(times.begin(), times.end(), [](const pair<int, int>& a, const pair<int, int> &b)->bool{
		if(a.second != b.second) return b.second < a.second;
		else return a.first < b.first;
	});

	for(auto pp : times){
		cout << pp.first << endl;
	}
}
