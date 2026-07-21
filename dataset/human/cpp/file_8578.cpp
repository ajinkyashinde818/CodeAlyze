#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m; cin >> n >> m;
    string a[n], b[m];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    bool ans;
    for(int i = 0; i < n-m+1; i++)
    {
        for(int j = 0; j < n-m+1; j++)
        {
            ans = true;
            for(int k = 0; k < m; k++)
            {
                if(a[i+k].substr(j, m)!=b[k]) ans = false;
            }
            if(ans){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}
