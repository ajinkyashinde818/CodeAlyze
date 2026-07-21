/*
Author: Fuadul Hasan(fuadul202@gmail.com)
BSMRSTU,Gopalganj
created: 20.02.2020
*/
#include <set>
#include <map>
#include <list>
#include <queue>
#include <ctime>
#include <deque>
#include <stack>
#include <cmath>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <chrono>
#include <random>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <fstream>
#include <climits>
#include <stdio.h>
#include <cstring>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
//#include<bits/stdc++.h>
using namespace std;
 
int         cinn()              {int x; scanf("%d", &x); return x;}
long long   cinl()              {long long x; scanf("%lld", &x); return x;}
double      cind()              {double x; scanf("%lf", &x); return x;}
void        coutt(int x)        {printf("%d ", x);}


#define  gcd(a,b)               __gcd(a,b)
#define  lcm(a,b)               (a*b)/gcd(a,b)
#define  PI                     acos(-1.0)
#define  vi                     std::vector<int>
#define  vll                    std::vector<ll>
#define  vit                    vector<int> :: iterator
#define  st                    	set<int> :: iterator
#define  mpsi                   std::map<string, int>
#define  pb                     push_back
#define  ll                     long long int
#define  ld                     long double
#define  ull                    unsigned long long int
#define  min3(a,b,c)            min(a,min(b,c))
#define  min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define  max3(a,b,c)            max(a,max(b,c))
#define  max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define  nl                     printf("\n");
#define  no                     printf("No");
#define  yes                    printf("Yes");
#define  F                      first
#define  S                      second
#define  happy					cin.tie(0);
#define  coding					ios::sync_with_stdio(false);

/*
	scanf("%[^\n]%*c", str);
*/

/*..........error........*/
#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s,char c) {vector<string>v;
stringstream ss(s);
string x;
while(getline(ss,x,c))
v.emplace_back(x);return move(v);}
void err(vector<string>::iterator it) {}
template<typename T,typename... Args>
void err(vector<string>::iterator it,T a,Args...args) {
cout<<it->substr((*it)[0]==' ',it->length())<< " = " << a << " ";
err(++it,args...);}
/*.........error...........*/

typedef pair<int,int> ii;
typedef std::vector<ii> vii;
 
const int mod           = 1e9 + 7;
const int inf           = (int)2e9 + 5;
const ll  Inf           = (ll)1e18 + 5;
const int N             = 1e7 + 5;
const int nn           = 3e5 + 5;

int a[nn];
int t[nn];
  

int solve()
{
	//happy coding
	int n=cinn(),m=cinn();
	if(n<10){
		cout<<(10-n)*100+m<<endl;
	}else{
		cout<<m<<endl;
	}


	//error();
	return 0;
}

int main()
{
    int test = 1, tc = 0;
    //scanf("%d", &test);
    //(void)getchar();
    //cin >> test;
    while (test--) {
        //printf("Case %d: ", ++tc);
        solve();
    }
 
    return 0;
}
