#include <bits/stdc++.h>
    using namespace std;
     
    vector<string>A, B;
     
    int main()
    {
        int N, M;
        cin>>N>>M;
       
        string inp;
        for(int i = 0; i < N; i++)
        {
            cin>>inp;
            A.push_back(inp);
        }
        for(int i = 0; i < M; i++)
        {
            cin>>inp;
            B.push_back(inp);
        }
        int i, j, k, l;
        int ans = 0;
        for(i = 0; i + M - 1 < N; i++)
        {
            for(j = 0; j + M - 1 < N; j++)
            {
                 for(k = 0; k < M; k++)
                 {
                     for(l = 0; l < M; l++)
                     {
                             if(A[i + k][j + l] != B[k][l]) break;
                     }
                     if(l < M) break;
                 }
                 if(k == M) ans++;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
