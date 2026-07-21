#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
 
    char A[50][50], B[50][50];
 
 
    for(int x = 0; x < N; ++x)
    {
        for(int y = 0; y < N; ++y)
        {
            cin >> A[x][y];
        }
    }
 
    for(int x = 0; x < M; ++x)
    {
        for(int y = 0; y < M; ++y)
        {
            cin >> B[x][y];
        }
    }
 
    bool exist = false;
 
    for(int lx = 0; lx < N; ++lx)
    {
        for(int ly = 0; ly < N; ++ly)
        {
            if(lx + M - 1 >= N or ly + M - 1 >= N)
                continue;
 
            bool match = true;
            for(int x = 0; x < M; ++x)
            {
                for(int y = 0; y < M; ++y)
                {
                    if(A[lx + x][ly + y] != B[x][y])
                        match = false;
                }
            }
            if(match)
                exist = true;
        }
    }
 
    if(exist)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    return 0;
}
