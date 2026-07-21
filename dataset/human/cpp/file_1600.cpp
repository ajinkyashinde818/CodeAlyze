#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    if(n==1){
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    else if(n==3){
        cout << "Yes" << endl;
        cout << 3 << endl;
        cout << 2 << " " << 1 << " " << 2 << endl;
        cout << 2 << " " << 2 << " " << 3 << endl;
        cout << 2 << " " << 3 << " " << 1 << endl;
        return 0;
    }
    vector<ll> a(100010, 0);
    for(ll i=4; i<=100000; i++){
        if(i*(i-1)/2>100000) break;
        a[i]=i*(i-1)/2;
    }

    bool is_yes=false;
    int num, sizes;
    for(int i=4; i<=100000; i++){
        if(n==a[i]){
            sizes=i;
            num=a[i];
            is_yes=true;
        }
    }

    if(is_yes==false){
        cout << "No" << endl;
    }
    else{
        vector<vector<int>> S(sizes);
        int number=1;
        for(int i=0; i<sizes; i++){
            for(int j=i+1; j<sizes; j++){
                S[i].emplace_back(number);
                S[j].emplace_back(number);
                number++;
            }
        }

        cout << "Yes" << endl;
        cout << sizes << endl;
        for(int i=0; i<sizes; i++){
            cout << S[i].size() << " ";
            for(int j=0; j<S[i].size(); j++){
                cout << S[i][j] << " ";
            }
            cout << endl;
        }

    }
    
}
