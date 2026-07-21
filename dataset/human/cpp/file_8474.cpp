#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char> (n));
    vector<vector<char>> b(m, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n;j++){
            cin >> a.at(i).at(j);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++){
            cin >> b.at(i).at(j);
        }

    bool exist = false; //あるかないかのチェック

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){  //Aの範囲で
            if(i+m-1>=n || j+m-1>=n) //検索範囲
                continue; //次へ 

            bool match = true; // 検索元画像と同じものがないかチェック
            for (int y = 0; y < m; y++){
                for (int x = 0; x < m; x++){
                    if(a.at(i+y).at(j+x)!=b.at(y).at(x)) // 選択範囲の要素とBを比較
                        match = false;
                }
    }
    if (match) exist = true;
        }
    }
    if(exist){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

    return 0;
}
