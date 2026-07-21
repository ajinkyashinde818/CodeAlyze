#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    vector<int> A(3);
    cin >> A.at(0) >> A.at(1) >> A.at(2) >> N;
    sort(A.begin(),A.end());
    int count = 0;
    for(int i = 0;i<N/A.at(2)+1;i++){
        int Na=N-i*A.at(2);
        for(int j = 0;j<Na/A.at(1)+1;j++){
            int Nb = Na -j*A.at(1);
            if(Nb%A.at(0)==0){
                count++;
            }
        }
    }
    cout << count << endl;
    
    
    return 0;
}
