#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define pye cout << "yes" << endl
#define pno cout << "no" << endl
#define pYe cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pYE cout << "YES" << endl
#define pNO cout << "NO" << endl
#define prin(num) cout << num << endl
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 100005
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

int main(void) {
    ll N;
    cin >> N;
    ll k;
    ll i, j, p=1;
    
    for(k=1; k*(k-1)/2<N; k++);
    
    if(N!=k*(k-1)/2) {
        pNo;
        return 0;
    }
    
    pYe;
    prin(k);
    set<ll> se[k];
    
    for(i=0; i<k; i++) {
        for(j=i+1; j<k; j++) {
            se[i].insert(p);
            se[j].insert(p);
            p++;
        }
    }
    
    for(i=0; i<k; i++) {
        cout << se[i].size() << " ";
        for(auto itr=se[i].begin(); itr!=se[i].end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }
    
}
