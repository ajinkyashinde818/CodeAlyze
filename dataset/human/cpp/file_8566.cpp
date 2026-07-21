#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);

    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    
    for(int i = 0; i < N-M+1; i++)
    {   
        for(int j = 0; j < N-M+1; j++)
        {   
            int judge = 0;
            
            for(int k = i; k < i+M; k++)
            {
                for(int l = j; l < j+M; l++)
                {
                    if(A[k][l]==B[k-i][l-j]){
                        judge++;
                    }
                }
                
            }
            if(judge == M*M){
                cout << "Yes" << endl;
                return 0;
            }
        }
        
    }

    cout << "No" << endl;
    return 0;
}
