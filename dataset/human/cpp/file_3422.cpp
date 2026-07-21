#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a;
    long sum = 0;
    int min_a = (int)1e9 + 1;
    int cnt = 0;
    for(int i=0; i<N; i++){
        cin >> a;
        sum += abs(a);
        min_a = min(min_a, abs(a));
        if(a < 0){
            cnt++;
        }
    }
    if(cnt % 2 == 0) cout << sum << endl;
    else cout << sum - min_a * 2 << endl;    
    return 0;
}
