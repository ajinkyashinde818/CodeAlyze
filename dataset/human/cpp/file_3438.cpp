#include "iostream"

using namespace std;

int main(){
	int N;
	cin >> N;
	long long A[N];
	for(int i = 0; i < N; i++){
        cin >> A[i];
    }

	long long ans = 0;
    int cnt = 0;
    long long min_A = abs(A[0]);
	for(int i = 0; i < N; i++){
        ans += abs(A[i]);
    }

    for(int i = 0; i < N; i++){
        min_A = min(min_A, abs(A[i]));

        if(A[i] < 0){
            cnt++;
        }
    }
    if(cnt % 2 == 1){
        ans -= 2 * min_A;
    }


	cout << ans << endl;


    return 0;
}
