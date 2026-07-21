#include "bits/stdc++.h"
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (n));
    vector<vector<int> > b(m, vector<int> (m));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
        a.at(i).at(j) = s.at(j);
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        b.at(i).at(j) = s.at(j);
    }//入力完了
    bool c = false;
    for(int i = 0; i < n - m + 1; i++){
        for(int j = 0; j < n - m + 1; j++){
            for(int k = 0; k < m; k++){
                bool d = true;
                for(int l = 0; l < m; l++){
                    if(a.at(i + k).at(j + l) != b.at(k).at(l)){
                    d = false;
                    break;
                    }
                    else if(k == m - 1 && l == m - 1){
                    c = true;
                    }
                }
                if(d == false)
                break;
            }
        }
    }
    if(c == true)
    cout << "Yes" << endl;
    else 
    cout << "No" << endl;
    return 0; 
}
