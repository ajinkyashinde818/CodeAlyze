#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v(3);
    for (int i = 0; i < 3; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater <int> ());

    int N;
    cin >> N;

    int count = 0;

    for (int i = 0; i < N / v[0] + 1; i++){
        for (int j = 0; j < (N - v[0] * i) / v[1] + 1; j++){
            if ((N - (v[0] * i + v[1] * j)) % v[2] == 0){
                count ++ ;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
