#include <iostream>
// #include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

#include <stack>
#include <queue>
// #include <deque>
// #include <set>
// #include <map>
// #include <string>
// #include <unordered_set>
// #include <unordered_map>

#include <tuple>
// #include <cmath>
// #include <numeric>

using namespace std;


typedef long long ll;
typedef pair<long,long> pll;
typedef pair<int,int> pii;
typedef pair<int,long> pil;
typedef pair<long,int> pli;
typedef pair<long long, long long> pllll;
typedef pair<long long, int> plli;
typedef pair<int,long long> pill;
typedef vector<vector<long long>> vvll;
typedef vector<vector<long>> vvl;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;

#define emplace_back pb
const char el = '\n';

/*
Edge cases:


*/

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,r; cin>>n>>r; cin.ignore();

    if (n>=10) {
        cout<<r;
    } else {
        cout<<r+100*(10-n);
    } cout<<el;
}
