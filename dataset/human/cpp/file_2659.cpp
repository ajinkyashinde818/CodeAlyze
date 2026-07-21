/*
 Author : Bisma
 @ copy from bisma template 1.0
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
#include <fstream>
#include <cstdio>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define repn(a,b,c) for(int a=b; a>=c; a--)
#define ll long long
#define mem(a, b) memset(a, (b), sizeof(a))
#define loop(a,b,c) for(int a = b ;a<c;a++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define FOR(a,b,c) for(int a = b ; a<c ; a++ )
ll max(ll a, ll b){
    if(a>b) return a;
    return b;
}

ll min(ll a, ll b){
    if(a>b) return b;
    return a;
}

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int lim = 1e5;

ll __gcd(ll a, ll b){

	if(b > a) swap(a,b);

	if(b == 0) return a;

	return __gcd(b, a % b);

}


ll a[(int)1e5 + 10];

int main(){

	fast();
	bool ada = false;

	ll n;

	cin>>n;

	ll pl = 0;
	ll mi = 0;

	rep(i,1,n){
		cin>>a[i];

		if(a[i] > 0 ){
			pl ++;
		}else{
			mi++;
		}

		if(a[i] == 0) ada = true;
	}

	if(ada){

		ll tot = 0;

		rep(i,1,n){
			tot += abs(a[i]);
		}

		cout<<tot<<endl;

	}else{
		//cout<<"LL"<<endl;
		ll tot = 0;

		//cout<<mi<<endl;

		if(mi % 2 == 0){

			rep(i,1,n){
				tot += abs(a[i]);
			}

		}else if(mi % 2 == 1){

			rep(i,1,n) a[i] = abs(a[i]);

			sort(a+1,a+n+1);

			rep(i,1,n){
				if(i == 1){
					tot-=a[i];
				}else{
					tot+=a[i];
				}
			}

		}


		
		cout<<tot<<endl;
	}
	
return 0;
}
