#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <cctype>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(n);
    string ans = "No";
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        a[i] = x;
    }
    for(int i=0;i<m;i++){
        string x;
        cin >> x;
        b[i] = x;
    }
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool flag = true;
            for(int k=0;k<m;k++){
                for(int p=0;p<m;p++){
                    if(a[i+k][j+p]!=b[k][p]){
                        flag = false;
                    }
    }
        
    }
    if(flag ==true){
        ans ="Yes";
        break;
    }
        }
    }
    cout << ans << endl;
}
