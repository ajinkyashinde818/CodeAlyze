#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<queue>
#include<math.h>
using namespace std ;
using ll = long long ;
using vi = vector<int> ;
using vii = vector<vi> ;
using pii = pair<ll,ll> ;

int main(){
	ll n,k ; cin >> n >> k ;
	if(n>=10) cout << k << endl ;
	else{
		cout << k+100*(10-n) << endl ;
	}
}
