/*Shivam Bhalla */
/* f2016941@pilani.bits-pilani.ac.in */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
long long maxv = 1e9;


int main(){
	  long long a[100010];
    //cout << fixed << setprecision(15);
    int N; cin >> N;
    int cnt=0;
    long long minV =1e9;
    for(int i=0; i<N; ++i){
        long long v; cin >> v;
        if(v<0){
            cnt++;
        }
        a[i] = v;
        minV = min(minV, abs(v));
    }

    long long ans=0;
    for(int i=0; i<N; ++i){
        ans += abs(a[i]);
    }

    if(cnt%2==0){  //if even number of negatives
        cout << ans << endl;
    }else{ //odd number of negatives
        cout << ans-2*minV << endl; // subtracting 2 into min because total has sbtract 2 times the minimum value
    }
    return 0;
}
