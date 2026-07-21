#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m;cin>>n>>m;
    string a[n],b[m];
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
        cin>>b[i];
    for (int i=0;i<=n-m;i++)
        for (int j=0;j<=n-m;j++) {
            for (int k=0;k<m;k++)
                for (int l=0;l<m;l++)
                    if (a[i+k][j+l]!=b[k][l])
                        goto aaa;
            puts("Yes");
            return 0;
            aaa:;
        }
    puts("No");
    return 0;
}
