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
int main(){
	int a,b,c,n,ans=0;
	cin>>a>>b>>c>>n;
	for (int i=0;i<=3000;i++)
		for (int j=0;j<=3000;j++){
			if (i*a+j*b>n || (i*a+j*b-n)%c) continue;
			ans++;
		}
	cout<<ans;
}
