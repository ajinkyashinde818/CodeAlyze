#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n;
    cin >> n;
    
    LL m = 0;
    bool ok = false;
    while(m*(m+1)/2 <= n && !ok){
        m++;
        if(m*(m+1)/2 == n){
            ok = true;
        }
    }

    if(!ok){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << m+1 << endl;

    vector<vector<LL>> triangle(m,vector<LL>(m));
    LL state = 1;
    cout << m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= i; j++){
            triangle[i][j] = state;
            if(i == j){
                cout << " " << state;
            }
            state++;
        }
    }
    cout << endl;

    for(int i = 0; i < m; i++){
        cout << m;
        for(int j = 0; j <= i ; j++){
            cout << " " << triangle[i][j];
        }
        for(int j = i+1; j < m; j++){
            cout << " " << triangle[j][i];
        }
        cout << endl;
    }
    
    return 0;
}
