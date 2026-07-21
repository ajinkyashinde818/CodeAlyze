#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

vector<int> res[1000];

int main(){
    int N;
    cin >> N;
    int k = 1;
    int ok = false;
    while(k*(k-1) <= 2*N){
        if(k*(k-1) == 2*N){
            ok = true;
            break;
        }
        else{
            k++;
        }
    }

    int num = k-1;
    if(ok){
        int count[1000];
        for(int i = 0; i < 1000; i++){
            count[i] = 0;
        }
        for(int i = 0; i < num; i++){
            res[0].push_back(i);
        }
        int ne = num;
        for(int i = 1; i < k; i++){
            for(int j = 0; j < num-i; j++) {
                res[i].push_back(ne);
                ne++;
            }
            for(int j = 0; j < i; j++){
                res[i].push_back(res[j][count[j]]);
                count[j]++;
            }
        }

        cout << "Yes" << endl;
        cout << k << endl;
        for(int i = 0; i < k; i++){
            cout << num << " ";
            for(int j = 0; j < num; j++){
                cout << res[i][j]+1 << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No" << endl;
    }




    return 0;

}
