#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> A;
    A.reserve(N);

    int temp;
    int count = 0;
    long long int sum = 0;
    int minimum = 10e9 + 1;
    for(int i = 0; i < N; i++){
        cin >> temp;
        A[i] = temp;
        if(temp < 0){
            count++;
        }
        sum += abs(temp);
        minimum = min(minimum, abs(temp));
    }

    long long int ans = 0;
    if(count % 2 == 0){
        ans = sum;
    }
    else{
        ans = sum - 2 * minimum;
    }

    cout << ans << "\n";

    return 0;
}
