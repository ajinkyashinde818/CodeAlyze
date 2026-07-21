#include<iostream>
#include<vector>
using namespace std;

// こんなの思いつかない
int main(){
    int n;
    cin >> n;

    int k;
    for(k = 1; k*(k-1) <= 2*n; k++){
        if(k*(k-1) == 2*n)    break;
    }

    if(k*(k-1) != 2*n){
        cout << "No" << endl;
        return 0;
    }

    int now = 1;
    vector<vector<int>> v(1000, vector<int>(1000, 0));
    for(int i = 0; now <= n; i++){
        for(int j = 0; j <= i; j++){
            v[i][j] = now++;
        }
    }

    vector<int> ans[k];
    for(int i = 0; i < k-1; i++)  ans[0].push_back(v[i][i]);
    for(int i = 1; i < k; i++){
        int ni = i-1, nj = 0;
        while(nj < ni)  ans[i].push_back(v[ni][nj]), nj++;
        while(ni < k-1) ans[i].push_back(v[ni][nj]), ni++;
    }

    cout << "Yes" << endl;
    cout << k << endl;
    for(int i = 0; i < k; i++){
        cout << k-1;
        for(int j = 0; j < k-1; j++)    cout << " " << ans[i][j];
        cout << endl;
    }
    return 0;
}
