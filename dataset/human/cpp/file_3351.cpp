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
typedef long long ll;
int n;
ll dp[100004][2];
ll a[100004];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	dp[2][0]=a[1]+a[2];
	dp[2][1]=-(a[1]+a[2]);
	for (int i=3;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i];
		dp[i][1]=max(dp[i-1][0]-2*a[i-1]-a[i],dp[i-1][1]+2*a[i-1]-a[i]);
	}
	cout<<max(dp[n][0],dp[n][1]);
}
