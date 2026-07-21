#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    int k;
    vector<int> ans[1000];
    cin >> N;
    bool find = false;
    for(int i = 1; i*(i-1)/2 <= N; i++){
        if(i*(i-1)/2 == N){
            find = true;
            k = i;
            break;
        }
    }
    if(find){
        int cnt = 1;
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                ans[i].push_back(cnt);
                ans[j].push_back(cnt);
                cnt++;
            }
        }
        //output
        cout << "Yes" << endl;
        cout << k << endl;
        for(int i = 0; i < k; i++){
            cout << k-1 << ' ';
            for(int j = 0; j < k-1; j++){
                cout << ans[i][j];
                if(j != k-1) cout << ' ';
            }
            cout << endl;
        }
    }else{
        cout << "No" << endl;
    }
}
