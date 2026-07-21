#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A;
    for (auto i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        A.push_back(x);
    }

    sort(A.begin(), A.end());
    int mcounter = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
            mcounter++;
        else
        {
            break;
        }    
    }
    long long max = 0;
    long long Abs=1000000000;
    for (int i = 0; i < N; i++)
    {
        Abs=min(Abs,abs(A[i]));
        max += abs(A[i]);
    }
    if (mcounter % 2 == 0){
        cout <<max <<endl;
        return 0;
    }
    else{
        max=max-2*Abs;
        cout <<max <<endl;
        return 0;
    }
   
    return 0;
}
