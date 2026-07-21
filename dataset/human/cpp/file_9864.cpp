#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int t[26];
typedef long long ll;
ll ans=1;
int main(){
	cin>>n>>s;
	for (int i=0;i<s.size();i++)
		t[s[i]-'a']++;
	for (int i=0;i<26;i++)
		ans=ans*(t[i]+1)%(1000000007);
	ans--;
	cout<<ans;
}
