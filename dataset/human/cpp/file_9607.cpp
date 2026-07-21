#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string A[N], B[M];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int flag = true;
            for (int k = 0; k < M; k++)
            {
                for (int l = 0; l < M; l++)
                {
//                    cout << i+k << "|" << j+l << endl;
                    if(i+k > N-1 || j+l > N-1){
                        flag = false;
                        break;
                    }else if(A[i+k][j+l] != B[k][l]){
                        flag = false;
                    }
                }
            }
            if(flag == true){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
