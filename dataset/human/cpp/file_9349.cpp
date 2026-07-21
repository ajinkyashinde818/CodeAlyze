#include <cstdio>
#include <iostream>
using namespace std;
#include <string>
char A[55][55];
char B[55][55];
int main(void)
{
    int n,m;
    cin>> n>>m;
    for (int i=0;i<n ;i++ )
    {
        scanf("%s",A[i]);
    }
    for (int j=0;j<m ;j++ )
    {
        scanf("%s",B[j]);
    }
    bool flag ;
    bool flag2;
    for (int i =0;i<=n-m ;i++ )
    {
        for(int j=0;j<=n-m;j++)
        {
            flag = true;
            flag2 = false;
            for (int p=0;p<m ;p++ )
            {
                for (int q=0;q<m ;q++ )
                {
                    if(A[i+p][j+q]==B[p][q])
                    {
                        flag2= true;
                    }
                    else
                    {
                        flag2 = false;
                    }
                    flag= flag&& flag2;
                }
            }
            if(flag==true)
            {
                cout << "Yes"<< endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
