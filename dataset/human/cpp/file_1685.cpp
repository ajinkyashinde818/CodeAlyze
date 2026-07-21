#include <bits/stdc++.h>
using namespace std;

long used[100001];

int main(void){
    long n;
    cin >> n;
    const long sn = floor(sqrt(2*n));
    const long q = 2*n/sn;
    const long r = 2*n%sn;
    //cout << sn << " " << q << " " << r << " " << endl;
    if( r!=0 || q-sn != 1 ){
        cout << "No" << endl;
        return 0;
    }
    vector<vector<long>> ans(q);
    long u_index = 1;
    ans[0].resize(sn);
    for(long j=0; j<sn; j++){
        ans[0][j] = u_index;
        used[u_index]++;
        u_index++;
    }
    for(long i=1; i<q; i++){
        ans[i].resize(sn);
        for(long j=0; j<i; j++){
            const auto it = find_if(ans[j].begin(), ans[j].end(),
                    [](long ii){ return used[ii]==1; });
            used[*it]++;
            ans[i][j] = *it;
        }
        for(long j=i; j<sn; j++){
            ans[i][j] = u_index;
            used[u_index]++;
            u_index++;
        }
    }
    cout << "Yes\n";
    cout << q << endl;
    for(long i=0; i<q; i++){
        cout << sn;
        for(long j=0; j<sn; j++){
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
