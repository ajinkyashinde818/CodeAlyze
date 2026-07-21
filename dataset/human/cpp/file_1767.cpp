#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> manip(m);
    vector<bool> used(n+1, false);
    for(int i=0; i<m; i++){
        cin >> manip[i];
    }

    for(int i=m-1; i>=0; i--){
        if(!used[manip[i]]){
            cout << manip[i] << endl;
            used[manip[i]] = true;
        }
    }
    for(int i=1; i<=n; i++){
        if(!used[i]){
            cout << i << endl;
        }
    }
    
    return 0;
}
