#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1[100],s2[100];
string t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s1[i];
    for(int j=0;j<m;j++)
        cin >> s2[j];
        
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            t+=s1[i][j];
        
    for(int i=0;i<t.size();i++){
        int g=0,cnt=0;
        for(int k=i;k<t.size();k+=n){
            string r = t.substr(k,m);
            if(r==s2[g]){
                cnt++; g++;
            }
            if(cnt==m){
                cout << "Yes";
                return 0;
            }
        }
        
    }
    cout << "No";
    return 0;
}
