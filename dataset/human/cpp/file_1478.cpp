#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
int main()
{
    ll N;
    cin >> N;

    int i = 1;
    while(true){
        if(i * (i + 1) / 2 == N){
            break;
        }
        if(i * (i + 1) / 2 > N){
            cout << "No" << endl;
            return 0;
        }
        i ++;
    }
    vector<int>* vecArray = new vector<int>[i + 1]; 
    cout << "Yes" << endl;
    cout << i + 1 << endl;
    ll cnt = 0;
    for(ll j1 = 0; j1 < i; j1++){
        for(ll j2 = j1 + 1; j2 < i + 1; j2++){
            vecArray[j1].push_back(cnt + 1);
            vecArray[j2].push_back(cnt + 1);
            cnt ++;
        }
    }

    for(int vecIndex = 0; vecIndex < i + 1; vecIndex ++){
        vector<int> vec = vecArray[vecIndex];
        cout << i << " ";
        for(int index = 0; index < vec.size(); index++){
            cout << vec[index];
            if(index != vec.size() - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
