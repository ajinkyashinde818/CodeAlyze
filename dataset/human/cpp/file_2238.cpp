#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
using namespace std;

typedef long long ll;
int main()
{
        int N;
        cin >> N;
        vector<ll> A(N);
        ll All = 0;
        ll MinasCount=0;
        ll MinNum = 1000000001;
        for(int i=0; i<N; i++){
                cin >> A[i];
                if(A[i] < 0){
                         All += -A[i];
                        MinasCount ++;
                }
                else
                        All += A[i];
                if(MinNum > labs(A[i])) MinNum = labs(A[i]);
        }
        if(MinasCount % 2 == 0) cout << All;
        else cout << All - 2*MinNum;

}
