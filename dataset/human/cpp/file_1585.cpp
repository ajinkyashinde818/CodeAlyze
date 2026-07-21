#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

void write(vector<vector<int> >& o){
	cout << "Yes" << endl;
	cout << o.size() << endl;
	for(int i=0;i<o.size();i++){
		cout << o[i].size();
		for(int j=0;j<o[i].size();j++){
			cout << " " << o[i][j];
		}
		cout << endl;
	}
}
int main() {
	int N;
	cin >> N;
	vector<vector<int> > ret;
	ret.push_back({1});
	ret.push_back({1});
	if(N==1){
		write(ret);
		return 0;
	}
	int i=1;
	int d=2;
	while(i+d<=N){
		ret.push_back({});
		for(int j=0;j<d;j++){
			ret[j].push_back(i+j+1);
			ret.back().push_back(i+j+1);
		}
		i+=d;
		d++;
		if(i==N){
			write(ret);
			return 0;
		}
	}
	cout << "No" << endl;


	return 0;
}
