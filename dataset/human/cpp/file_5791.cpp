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
typedef array<int,3> A;

vector<A> nodes;
void push(string& s){
	int i=0;
	int c=0;
	while(i<s.size()){
		int v=s[i]-'0';
		if(nodes[c][v]==0){
			nodes[c][v]=nodes.size();
			nodes.push_back(A{{}});
		}
		c=nodes[c][v];
		i++;
	}
	nodes[c][2]=1;
}
LL g(LL h){
	LL u=1;
	while((h&u)==0){
		u<<=1;
	}
	return u;
}
LL f(int i,LL h){
	if(nodes[i][2]==1){
		return 0;
	}
	LL ret=0;
	for(int j=0;j<2;j++){
		if(nodes[i][j]){
			ret^=f(nodes[i][j],h-1);
		}
		else{
			ret^=g(h-1);
		}
	}
	return ret;
}
int main() {
	LL N,L;
	cin >> N >> L;
	nodes.push_back(A{{}});
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		push(s);
	}
	if (f(0,L+1)){
		cout << "Alice" << endl;
	}
	else{
		cout << "Bob" << endl;
	}

	return 0;
}
