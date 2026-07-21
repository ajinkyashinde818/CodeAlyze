#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main( void )
{
    long long N;
    cin >> N;

    long long A[N] = {};
    long long absmin = 1000000000LL;
    long long result = 0;
    int hugou = 1; // now only positive
    for(int i=0;i<N;i++){
        cin >> A[i];
        long long tmp = abs(A[i]);
        if(tmp < absmin){
            absmin = tmp;
        }
        if(A[i] < 0){
            hugou *= -1;
        }
        result += tmp;  
    }

    if(hugou == -1){
        result -= 2*absmin;
    }

    cout << result;


	return 0;
}
