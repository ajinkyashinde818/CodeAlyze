#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
 
using namespace std;
const int MAX = 100000;

int main(){
    int N,K;
    vector<int> ans[MAX];

    cin >> N;

    while(K * (K + 1) / 2 < N)K++;

    if(K * (K + 1) / 2 != N){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << ++K << endl;

    int n = 1;
    for(int i = 1;i <= K;i++){
        for(int j = i + 1;j <= K;j++){
            ans[i - 1].push_back(n);
            ans[j - 1].push_back(n);
            n++;
        }
    }

    for(int i = 0;i < K;i++){
        cout << ans[i].size();
        for(int j = 0;j < ans[i].size();j++){
            cout << ' ';
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
