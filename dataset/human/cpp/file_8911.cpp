#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for(int i = 0;i < n;i++)cin >> a.at(i);
    for(int i = 0;i < m;i++)cin >> b.at(i);
    for(int ay = 0;ay < n;ay++){
        for(int ax = 0;ax < n;ax++){
            if(n - m + 1 <= ay || n - m + 1 <= ax)break;
            bool judge = true;
            for(int by = 0;by < m;by++){
                for(int bx = 0;bx < m;bx++){
                    if(a.at(ay + by).at(ax + bx) != b.at(by).at(bx))judge = false;
                }
            }
            if(judge){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
