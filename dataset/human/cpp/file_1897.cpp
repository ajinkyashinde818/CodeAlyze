#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <ctime>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;



int isok(vector<int> &b){
	for(int i = 0 ; i < b.size() ; i++)
		if( b[i] != i+1 ) return 0;
	return 1;
}
int main(){
	int Q;
	cin >> Q;
	while(Q--){
		long long n = 0;
		for(int i = 0 ; i < 8 ; i++){
			char c;
			cin >> c;
			if( c >= 'a' ) c = c - 'a' + 10;
			else c = c - '0';
			n = 16 * n + (long long)c;
		}
		if( n & (1ll<<31) ){
			cout << "-";
		}
		//cout << "[" << n << endl;
		n = n & ~(1ll<<31);
		long long a = n / (1ll<<7);
		long long b = n % (1ll<<7);
		double B = 0 , W = 0.5;
		for(int i = 0 ; i < 7 ; i++){
			B += (b>>(6-i)&1) * W;
			W *= 0.5;
		}
		char tmp[128];
		sprintf(tmp,"%.16lf",(double)(a+B));
		string s = tmp;
		while(s[s.size()-1] == '0' && s[s.size()-2] != '.') s = s.substr(0,s.size()-1);
		cout << s << endl;
	}
}
