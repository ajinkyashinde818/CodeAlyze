#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}

ll minll(ll a, ll b){
    if(a >= b)  return b;
    else    return a;
}

ll maxll(ll a, ll b){
    if(a >= b)  return a;
    else    return b;
}

ll n,m;
string a[100],b[100];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == b[0][0]){
                flag = true;
                for(int k = 0; k < m; k++){
                    for(int l = 0; l < m; l++){
                        ll a_i = i+k;
                        ll a_j = j+l;
                        if(a_i > n || a_j > n){
                            flag = false;
                            break;
                        }
                        if(a[a_i][a_j] != b[k][l]){
                            flag = false;
                            break;
                        }  
                    }
                }
                if(flag){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
}
