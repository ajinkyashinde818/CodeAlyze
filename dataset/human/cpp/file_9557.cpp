#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for (int i=0;i<n;i++){
        cin >> a.at(i);
    }
    for (int i=0;i<m;i++){
        cin >> b.at(i);
    }
    vector<int> tmp;
    string ans = "No";
    for (int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            int cnt =0;
            for (int k=0;k<m;k++){
                for (int l=0;l<m;l++){
                    if(a[i+k].at(j+l)==b[k].at(l))
                        cnt++;
                }
            }
            if(cnt==m*m){
                ans = "Yes";
            }
        }
    }

    cout << ans << endl;
    return 0;
}
