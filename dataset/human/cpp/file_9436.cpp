#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char A[n][n],B[m][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>A[i][j];
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            cin>>B[i][j];
    bool f = false;
    for(int i=0; i<n-m+1; i++)
    {

        for(int j=0; j<n-m+1; j++)
        {
            f = true;
            for(int k=i; k<i+m; k++)
            {
                for(int l=j; l<j+m; l++)
                {
                    //cout<<"A: "<<A[k][l]<<"B :"<<B[k-i][l-j]<<endl;
                    if(A[k][l]!=B[k-i][l-j])
                    {
                        f = false;
                        break;
                    }

                }
                if(!f)
                    break;
            }
            if(f)
                break;
        }
        if(f)
            break;

    }
    if(f)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


}
