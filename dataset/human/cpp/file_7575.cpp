#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>

#define REP(i,N) for(auto i = 0; i <N; i++)


typedef long long ll;
//const int MOD = pow(10,9)+7;
//const int MAX = 100001;

using namespace std;
int in(){
    int temp;
    scanf("%d",&temp);
    return temp;
}

ll lin(){
    ll temp;
    scanf("%lld",&temp);
    return temp;
}


int main() {

    ll N = lin();
    
    vector<ll> cards;

    ll sum = 0;
    REP(i,N){
        cards.push_back(lin());
        sum+=cards.back();
    }
    
    ll ansS = 0;
    ll ansA = sum;
    
    ll diff = LONG_MAX;
    
    for(auto i = 0; i < N-1; i++){
        
        ansS+=cards[i];
        ansA-=cards[i];
        
        if (diff > abs(ansA-ansS)) diff = abs(ansA-ansS);
    }
    
    cout << diff << endl;
    
    
    return 0;
    
    
}
