/*
    coder:xxjAc
    name:Jury Marks
    time：2017/7/13 
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int a[200007];
int main(){
	int n;
	cin>>n;
	long long nw=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		nw+=a[i];
	}
	long long ans=76891462189;
	int i=n-1;
	while (i>=1){
		nw-=a[i]*2;
		i--;
		if (nw>=0){
			ans=min(ans,nw);
		}
		else{
			ans=min(ans,0-nw);
		}
	}
	cout<<ans<<endl;
	return 0;
}
