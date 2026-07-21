#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int N, M;
    
    cin >> N >> M;
    vector<string> A, B;
    A.resize(N);
    B.resize(M);
    
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    
    bool flag;
    for(int i = 0; i < N - M + 1; i++)
    {
        for(int j = 0; j < N - M + 1; j++)
        {
            int starti = i;
            int startj = j;
            
            flag = true;

            for(int k = 0; k < M; k++)
            {
                for(int l = 0; l < M; l++)
                {
                    if (A[k+starti][l+startj] != B[k][l])
                    {
                        flag = false;
                        break;
                    }
                    
                }
            }

            if(flag)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
    
    return 0;
}
