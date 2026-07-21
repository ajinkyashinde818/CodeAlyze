#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

 int main(){
    int N;
    vector<long long int> A;

    cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    
    bool flag_allplus = true;
    for(int i=0; i<N; i++){
        if(A[i] < 0){
            if(flag_allplus) flag_allplus = false;
            else flag_allplus = true;
        }
    }

    long long int sum = 0;
    if(flag_allplus){
        for(int i=0; i<N; i++)
            sum += abs(A[i]);
    }else{
        int min = 0, min_id = 0;
        for(int i=0; i<N; i++){
            if(i == 0) min = abs(A[i]);
            else if(abs(A[i]) < min) {
                min = abs(A[i]);
                min_id = i;
            }
        }

        for(int i=0; i<N; i++){
            if(i == min_id) sum += std::min(A[i], -A[i]);
            else sum += abs(A[i]);
        }
    }

    cout << sum << endl;
 }
