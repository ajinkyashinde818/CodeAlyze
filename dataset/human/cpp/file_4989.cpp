#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0xffffffffff;
const int N = 1e5 + 100;
int n, k;


int main() {
	cin>>n>>k;
    if(n >= 10) {
    	cout<<k<<endl;
    }else {
    	cout<<k+100 * (10 - n)<<endl;
    }
    return 0;
}
