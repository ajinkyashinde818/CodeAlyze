#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll N, L;

ll Grundy(ll x){
    ll ret = 1;
    if(x == 0){
        return 0;
    }

    while(x % 2 == 0){
        ret *= 2;
        x /= 2;
    }
    return ret;
}

class Trie{
public:
    Trie *zero, *one;
    ll depth;

    Trie(ll d){
        zero = nullptr;
        one = nullptr;
        depth = d;
    }

    void make_zero(){
        if(zero==nullptr){
            zero = new Trie(depth+1);
        }
    }

    void make_one(){
        if(one==nullptr){
            one = new Trie(depth+1);
        }
    }
};

ll solve(Trie t){
    ll ans = 0;
    if(t.zero==nullptr){
        ans^=Grundy(L-t.depth);
    }
    else{
        ans^=solve(*t.zero);
    }

    if(t.one==nullptr){
        ans^=Grundy(L-t.depth);
    }
    else{
        ans^=solve(*t.one);
    }

    return ans;
}


int main(){
    cin >> N >> L;
    Trie t = Trie(0);
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        Trie *it = (&t);
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '0'){
                it->make_zero();
                it = it->zero;
            }
            else{
                it->make_one();
                it = it->one;
            }
        }
    }

    if(solve(t) > 0){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
    }


    return 0;

}
