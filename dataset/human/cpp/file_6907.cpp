#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }

    vector<int> cnt(N + 1, 0);
    for(int i = 0; i < N; i++){
        cnt[A[i]]++;
        cnt[B[i]]++;
    }

    for(int i = 1; i <= N; i++){
        if(cnt[i] > N){
            cout << "No" << endl;
            return 0;
        }
    }

    reverse(B.begin(), B.end());

    vector<bool> same(N);
    int sameNum = -1;
    for(int i = 0; i < N; i++){
        if(A[i] == B[i]){
            same[i] = true;
            sameNum = A[i];
        }
        else{
            same[i] = false;
        }
    }

    int diffIndex = 0;
    int sameIndex = 0;
    while(sameIndex < N && diffIndex < N){
        while(sameIndex < N && !same[sameIndex]){
            sameIndex++;
        }
        if(sameIndex == N){
            break;
        }

        while(diffIndex < N && (same[diffIndex] || A[diffIndex] == sameNum || B[diffIndex] == sameNum)){
            diffIndex++;
        }
        if(diffIndex == N){
            break;
        }

        swap(B[sameIndex], B[diffIndex]);
        sameIndex++;
        diffIndex++;
    }

    cout << "Yes" << endl;
    for(int i = 0; i < N; i++){
        cout << B[i];
        if(i == N - 1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }

    return 0;
}
