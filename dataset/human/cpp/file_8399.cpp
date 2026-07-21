#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <deque>
using ll = long long;
using namespace std;

int n, m;
vector<string> A, B;

bool check(int y, int x){
    bool flag = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if(A[i+y][j+x] == B[i][j])continue;
            else{
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main(){
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        A.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        B.push_back(s);
    }
    for (int i = 0; i <= n-m; i++) {
        for (int j = 0; j <= n-m; j++) {
            if(check(i,j)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
