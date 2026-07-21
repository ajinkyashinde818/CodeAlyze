#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
pair<int, int> p1[200001], p2[200001];

int main() {
    int n;
    cin >> n;
    int sq = sqrt(8*n + 1);
    if(sq * sq == 8* n + 1){
        cout << "Yes\n";
        int a = (sq - 1)/2;
        cout << (a + 1) << "\n";
        int ans[a + 1][a];
        int now = 1;
        for(int i = 0; i < a; i++){
            for(int j = 0; j + i < a; j++){
                ans[i][i + j] = now;
                ans[i + 1 + j][i] = now;
                now++;
            }
        }
        for(int i = 0; i <= a; i++){
            cout << a << " ";
            for(int j = 0; j < a; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }else{
        cout << "No\n";
    }
    return 0;
}
