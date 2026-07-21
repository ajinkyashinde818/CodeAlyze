#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, min = 1e9;
    cin >> N;
    int A[N+1];
    long long ans, sum = 0;
    int count = 0;
    bool flag = false;
    

    for(int i=0; i<N; i++){
	cin >> A[i];
    }

    for(int i=0; i<N; i++){
	if(A[i] < 0)
	    count++;
	else if(A[i] == 0){
	    flag = true;
	}

	if(abs(A[i]) < min)
	    min = abs(A[i]);	
	sum += abs(A[i]);	
    }

    if(count%2 == 0)
	flag = true;

    if(flag)
	ans = sum;
    else
	ans = sum -2*min;

    cout << ans << endl;            

}
