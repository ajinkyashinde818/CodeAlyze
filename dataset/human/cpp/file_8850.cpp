// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , m ;
    cin >> n >> m;

    char ar[n+1][n+1];
    char br[m+1][m+1];

    for(int i=0;i<n;i++)cin >> ar[i];
    for(int i=0;i<m;i++)cin >> br[i];

    if(m>n)cout << "No" << endl;
    else if(m==n){

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]!=br[i][j]){

                    cout << "No" << endl;
                    return 0;
                }
            }
        }

        cout << "Yes" << endl;

        return 0;
    }
    else{

        bool check = true;

        for(int i=0;i<n-m;i++){

            for(int j=0;j<n-m;j++){

                check = true;

                for(int k=0;k<m;k++){

                    for(int l=0;l<m;l++){

                        if(ar[i+k][j+l]!=br[k][l])check=false;
                    }
                }

                if(check==true){

                    cout << "Yes" << endl;
                    return 0;
                }
            }


        }
    }

    cout << "No" << endl;
    return 0;
}
