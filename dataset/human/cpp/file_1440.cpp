#include<bits/stdc++.h>
using namespace std;

int main(){

    int N; cin >> N;
    int n = -1;
    for(int i = 0; i < 1000000; i++){
        if(N == i * (i - 1) / 2){
            n = i;
            break;
        }
    }
    if(N == 1){
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        
    }else if(n == -1) cout << "No" << endl;
    else{
        vector<vector<int> > G(n, vector<int> (n, -1));
        int num = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                if(G[i][j] == -1){
                    G[i][j] = G[j][i] = num;
                    num++;
                }
            }
        }

        //cout << num << endl;

        cout << "Yes" << endl;
        cout << n << endl;
        for(int i = 0; i < n; i++){
            cout << n - 1 << " ";
            int cnt = 1;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(n - 1 == cnt) cout << G[i][j] << endl;
                else cout << G[i][j] << " ";
                cnt++;
            }
        } 

    }

    return 0;
}
