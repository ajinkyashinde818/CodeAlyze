#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n;
	cin>>n;
	if(n==1){
		cout<<"Yes"<<endl;
		cout<<2<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	if(n==2){
		cout<<"No"<<endl;
		return 0;
	}
	int k=1;
	while(k*(k-1)/2<n) k++;
	if(k*(k-1)/2>n){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	vector<int> v[10000];
	v[0].push_back(1);
	v[0].push_back(2);
	v[1].push_back(2);
	v[1].push_back(3);
	v[2].push_back(1);
	v[2].push_back(3);
	int c=4;
	for(int i=4; i<=k; i++){
		int c1=c;
		for(int j=0; j<i-1; j++){
			v[i-1].push_back(c);
			c++;
		}
		for(int j=0; j<i-1; j++){
			v[j].push_back(c1);
			c1++;
		}
	}
	cout<<k<<endl;
	for(int i=0; i<k; i++){
		cout<<v[i].size()<<" ";
		for(int j=0; j<v[i].size()-1; j++) cout<<v[i][j]<<" ";
		cout<<v[i][v[i].size()-1]<<endl;
	}

    return 0;
}
