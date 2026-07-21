#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <fstream>
#include <numeric>
#define ll long long 
#define pb push_back
#define INF (ll)1e18
#define IINF (int)1e9 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);   
#define MOD 1000000000 + 7
#define F first 
#define S second
#define sp << " " << 
/*rrrohan*/ 
using namespace std; 
 
/*less than or equal to -> l + r + 1*/
 
/*class dsu{
private: 
	vector <int> r,p; 
public: 
	dsu(int n){
		p.resize(n+1);
		r.resize(n+1);  
		for(int i = 0; i < n+1; i++){
			p[i] = i; 
			r[i] = 0; 
		}
	}
	int findset(int i){
		return (p[i] == i) ? i : (p[i] = findset(p[i])); 
	}
	bool issameset(int a, int b){
		return findset(a) == findset(b); 
	}
	void unionset(int i, int j){
		if(!issameset(i,j)){
			int x = findset(i), y = findset(j); 
			if(r[x] > r[y]){
				p[y]  = x; 
			}else{
				p[x] = y; 
				if(r[x] == r[y]){
					r[y]++; 
				}
			}
		}
	}
};
*/ 


int main(){
	int n; 
	cin >> n; 
	int arr[n];  
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
	ll dp[n-1][2];
	for(int i = 0; i < n-1; i++){
		dp[i][0] = -INF, dp[i][1] = -INF; 
	} 
	dp[0][0] = arr[0] + arr[1], dp[0][1] = -(arr[0] + arr[1]);  
	for(int i = 1; i < n-1; i++){
		 dp[i-1][0] = dp[i-1][0] - arr[i];
		 dp[i-1][1] = dp[i-1][1] + arr[i]; 
		 ll sum = arr[i] + arr[i+1], sum2 = -arr[i] + arr[i+1]; 
		 dp[i][0] = max(dp[i][0], dp[i-1][0] + sum); 
		 dp[i][0] = max(dp[i][0], dp[i-1][1] + sum2);
		 dp[i][1] = max(dp[i][1], dp[i-1][0] - sum); 
		 dp[i][1] = max(dp[i][1], dp[i-1][1] - sum2);    
	}
	cout << max(dp[n-2][0], dp[n-2][1]); 
}
