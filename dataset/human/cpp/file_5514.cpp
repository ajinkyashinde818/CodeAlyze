//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <chrono>
#include <numeric>

using namespace std;
using namespace std::chrono;

typedef long long int lo;
#define fast ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(0);
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define inf (lo)1e9
#define N (lo)1e5 * 5
#define all(x) (x).begin(), (x).end()
#define ii pair<lo,lo>
#define iii pair<lo, pair<lo,lo> >
#define si pair<string,lo>
#define vi vector <lo> 
#define vii vector <ii> 

int main() {
    fast
    lo n,r;
    cin >> n >> r;
    if(n < 10){
        cout << r + 100 * (10 - n) << endl;
    }
    else{
        cout << r << endl;
    }
    return 0;
}
