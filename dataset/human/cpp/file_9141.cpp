#include <bits/stdc++.h>
using namespace std;

bool templete_matching(vector<string> A, vector<string> B, int n, int m){
    for(int ay = 0; ay < n - m + 1; ay++){
        for(int ax = 0; ax < n - m + 1; ax++){
            
            bool flag = true;
            
            for(int by = 0; by < m; by++){
                for(int bx = 0; bx < m; bx++){
                    
//                    cout << A.at(ay+by).at(ax+bx) << " " << B.at(by).at(bx) << endl;
                    if(A.at(ay+by).at(ax+bx) != B.at(by).at(bx)){
                        flag = false;
                        break;
                    }
                }
                if(flag == false){
                    break;
                }
            }
            if(flag == true){
                return true;
            }
            
        }
    }
    
    return false;
}
int main(){
    int n, m; cin >> n >> m;
    
    vector<string> A(n);
    for(int i = 0; i < n; i++){
        cin >> A.at(i);
    }
    
    vector<string> B(m);
    for(int i = 0; i < m; i++){
        cin >> B.at(i);
    }
    
    if(templete_matching(A, B, n, m)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
