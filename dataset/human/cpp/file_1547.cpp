#include <iostream>
#include <vector>

using namespace std;

int findGroup(int N){
    for(int i=2;;i++){
        int sum = i*(i-1)/2;
        if(sum == N) return i;
        if(sum > N) return -1;
    }
    return -1;
}

vector<vector<int>> solve(int N){
    int group = findGroup(N);
    if(group == -1 || 2*N%group != 0) return vector<vector<int>>();
    vector<vector<int>> res(group, vector<int>(group-1, 0));
    int v = 1;
    for(int i=0;i<group-1;i++){
        for(int j=i;j<group-1;j++){
            res[i][j] = res[j+1][i] = v;
            ++v;
        }
    }
    return res;
}

int main(){
    int N;
    while(cin >> N){
        auto res = solve(N);
        if(res.empty()){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            cout << res.size() << endl;
            for(auto& v : res){
                cout << v.size();
                for(auto& t : v) cout << " " << t;
                cout << endl;
            }
        }
    }
}
