//D
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807

int N;
int A[100000] = {};
int nex = 0;
vector<int> S[1000];

int solve(int size, int now){
    for(int i=0; i<now; i++){
        S[now].push_back(S[i][now-1]);
        A[S[i][now-1]]++;
    }
    size -= now;
    while(size > 0){
        if(A[nex] != 0){
            nex++;
            continue;
        }
        S[now].push_back(nex);
        A[nex]++;
        nex++;
        size--;
    }
}

int main(){
    
    cin >> N;//max99681
    int tmp = 0;
    int i;
    for(i=1; i<1000; i++){//Max448
        tmp += i;
        if(tmp > N){
            cout << "No" << endl;
            return 0;
        }
        if(tmp == N) break;
    }
    cout << "Yes" << endl;
    cout << i+1 << endl;
    for(int j=0; j<i+1; j++){
        cout << i;
        solve(i, j);
        for(int k=0; k<i; k++){
            cout << " " << S[j][k]+1;
        }
        cout << endl;
    }
    
    return 0;
}
