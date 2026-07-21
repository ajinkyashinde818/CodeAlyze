#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

void print_ans(bool flag){
    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }   
}

int main(){
    int n, m;
    cin >> n >> m;
    char a[n][n];    
    char b[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    bool ans = false;
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            bool res = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    res &= (b[k][l] == a[i+k][j+l]);
                    if(!res){
                        break;
                    }
                }
            }
            if(res){
                ans = true;
                break;
            }
        }
        if(ans){
            break;
        }
    }
    print_ans(ans);
    return 0;
}
