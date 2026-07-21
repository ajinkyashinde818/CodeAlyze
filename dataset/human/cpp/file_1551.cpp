#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int N;
    cin >> N;
    for(ll k=1;k*(k-1)/2<=N;k++){
        if(k*(k-1)/2==N){
            cout << "Yes" << endl << k << endl;
            set<int> ans[1000];
            int l=1,r=2;
            for(int idx=1;idx<=N;idx++){
                ans[l].insert(idx);
                ans[r].insert(idx);
                r++;
                if(r>k){
                    l++;
                    r=l+1;
                }
            }
            for(int i=1;i<=k;i++){
                cout << k-1;
                for(int x:ans[i]) cout << " " << x;
                cout << endl;
            }
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}
