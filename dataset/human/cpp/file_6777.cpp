#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <bitset>
#include <list>

using namespace std;


#define INF pow(10, 9)
// typedef priority_queue<tuple<int,int,int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > PQ;

typedef long long int ll;




int main(void)
{

    int N;
    cin >> N;
    int NMax = pow(10, 5) * 2+1;
    vector<int> A(N), B(N), Count(NMax, 0);

    for(int i=0; i<N; i++)
    {
        cin >> A[i];
        Count[ A[i] ] ++;
    }
    bool flag = true;

    for(int i=0; i<N; i++)
    {
        int j = N-1-i;
        cin >> B[j];
        Count[ B[j] ] ++;
        if(Count[ B[j] ] > N)
        {
            flag = false;
            break;
        }
    }

    if(flag==false)
    {
        cout << "No" << endl;
    }
    else
    {
        int left = 0;
        for(int i=0; i<N; i++)
        {
            if(A[i] == B[i])
            {
                while(left<N && (A[left]==B[i] || A[i]== B[left]) )
                {
                    left ++;
                }
                swap(B[i], B[left]);
            }
        }
        cout << "Yes" << endl;
        for(int i=0; i<N; i++)
        {
            cout <<B[i] << " ";
        }
        cout << endl;
    }





    return 0;
}
