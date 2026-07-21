#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    int i,j,k,l;
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    for(i = 0;i < m;++i){
        cin >> b.at(i);
    }
    bool flag = false;
    for(i = 0;i <= n-m;++i){
        for(j = 0;j <= n-m;++j){
            for(k = 0;k < m;++k){
                for(l = 0;l < m;++l){
                    if(a.at(i+k).at(j+l) != b.at(k).at(l)){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    flag = false;
                    break;
                }
            }
            if(k == m){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
