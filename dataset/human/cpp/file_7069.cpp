//#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <math.h>
#include <assert.h>
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
using namespace std;
int n, a[200009], first[200009], b[200009], nb[200009];
int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
        first[i] = -1;
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        if(first[b[i]] == -1)
            first[b[i]] = i;
    }
    int shift = 0;
    for(int i=1;i<=n;i++) {
        if(first[a[i]] != -1 && (i == n || a[i] != a[i + 1])) {
            int curshift = i + 1 - first[a[i]];
            shift = max(shift, curshift);
        }
    }
    //cout<<shift<<endl;
    for(int i=1;i<=n;i++) {
        int ind = i - shift;
        if(ind < 1)
            ind += n;
        //cout<<i<<" "<<ind<<endl;
        nb[i] = b[ind];
        if(nb[i] == a[i]) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
        cout<<nb[i]<<" ";
}
/*
 2
 1 1
 1 0
 1 1
 1 1
 */
