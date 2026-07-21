#include<bits/stdc++.h>
using namespace std;

int check(vector<string> s, vector<string> c, int i, int j){
    int size_c = c.size();
    int flag = 0;
    for(int t = 0; t < size_c; t++){
        for(int k = 0; k < size_c; k++){
            if(s[i + t][j + k] != c[t][k]){
                flag = 1;
                break;
            }
        }
    }

    return flag;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<string> c(m);
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }

    int flag = 1;
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            flag = 1;
            if(s[i][j] == c[0][0]){
                flag = check(s, c, i, j);
            }

            if(flag == 0){
                break;
            }
        }

        if(flag == 0){
            break;
        }
    }

    if(flag == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
