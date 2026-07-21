#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    string a[100], b[100];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    bool isok = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j+m-1>=n || i+m-1>=n) continue;
            bool match = true;

            for(int y=0; y<m; y++){
                for(int x=0; x<m; x++){
                    if(a[j+y][i+x]!=b[y][x]) match=false;
                }
            }
            if(match) isok = true;

        }
    }

    if(isok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
