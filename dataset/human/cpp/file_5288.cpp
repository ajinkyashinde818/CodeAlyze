//#include <fsociety>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
//end of libraries ;
#define INF 9999999999
#define N 300003
#define F first
#define S second
#define pb push_back
#define ll long long
#define fcin ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int n , r;
int main(){
fcin;
	cin>>n>>r;
	if(n>=10) cout<<r<<endl;
	else cout<<100*(10-n)+r<<endl;

}
