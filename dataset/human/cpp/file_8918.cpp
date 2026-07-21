#include<bits/stdc++.h>
using namespace std;
int M, N;
char a[202][202];
char b[202][202];
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i) cin>>a[i];
    for(int i=0; i<M; ++i) cin>>b[i];
    for(int i=0; i<=N-M; ++i)
        for(int j=0; j<=N-M; ++j)
        {
            bool flag = true;
            for(int k=0; k<M; ++k)
                for(int s=0; s<M; ++s)
                    if(a[k+i][s+j]!=b[k][s])
                        flag=  false;
            if(flag)
            {
                puts("Yes");
                return 0;
            }
        }
    puts("No");
    return 0;
}
