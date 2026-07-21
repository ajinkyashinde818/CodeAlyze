#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

const int MAX = 50;
char a[MAX][MAX], b[MAX][MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    bool included = false;
    for (int ay = 0; ay < n; ay++){
        for (int ax = 0; ax < n; ax++){
            if ((ay + m > n) || (ax + m > n)) continue; //はみ出たら

            bool match = true; //一致するか判定
            for (int by = 0; by < m; by++){
                for (int bx = 0; bx < m; bx++){
                    if(a[ay + by][ax + bx] != b[by][bx]){
                        match = false; //違うときだけ変更
                    }
                }
            }
            if(match == true) included = true;
        }
    }
    if(included == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
