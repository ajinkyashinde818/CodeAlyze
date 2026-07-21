#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n;i++)
        cin >> b[i];
    reverse(b.begin(), b.end());

    vector<int> c, d;
    int v = -1;
    int cnt = 0;
    for (int i = 0; i < n;i++){
        if(a[i] == b[i]){
            cnt++;
            v = b[i];
            c.push_back(i);
        }
    }
    for (int i = 0; i < n && cnt;i++){
        if(a[i] != b[i] && a[i]!=v && b[i]!=v){
            d.push_back(i);
            cnt--;
        }
    }
    if(cnt)
        cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        for (int i = 0; i < (int)d.size();i++)
            swap(b[c[i]], b[d[i]]);
        for (int i = 0; i < n;i++)
            cout << b[i] << ' ';
    }


    return 0;
}
