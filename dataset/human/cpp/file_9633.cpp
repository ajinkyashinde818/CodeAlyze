#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m; cin>>n>>m;
    string a[n]; for(auto& s: a) cin>>s;
    string b[m]; for(auto& s: b) cin>>s;

    for(int i=0; i+m<=n; ++i)
        for(int j=0; j+m<=n; ++j) {
            for(int k=0; k<m; ++k)
                for(int l=0; l<m; ++l)
                    if (a[i+k][j+l]!=b[k][l]) goto HOGE;
            cout<<"Yes"<<endl;
            return 0;
HOGE:;
        }
    cout<<"No"<<endl;
}
