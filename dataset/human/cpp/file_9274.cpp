#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;

const double PI  = 3.141592653589793238463;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> bigger(n);
    vector<string> smaller(m);
    for(int i = 0; i < n; i++){
        cin >> bigger[i];
    }
    for(int i = 0; i < m; i++){
        cin >> smaller[i];
    }
    
    for(int i = 0; i <= n-m; i++){
        for(int j = 0; j <= n-m; j++){
            bool t = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(bigger[i+k][j+l] != smaller[k][l]){
                        t = false;
                    }
                }
            }
            if(t){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No";
    cout << endl;
}
