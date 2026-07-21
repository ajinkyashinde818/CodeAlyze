#include <bits/stdc++.h>
using namespace std;
int n,m;
string A[60],B[60];
int fc(int x,int y)
{
    for (int i = 0;i < m;i++)
        for (int j = 0;j < m;j++)
            if (B[i][j] != A[i+x][j+y])
            return 0;
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> A[i];
    for (int i = 0;i < m;i++) cin >> B[i];
    for (int i = 0;i <= n-m;i++)
        for (int j = 0;j <= n-m;j++)
        if (fc(i,j)) {printf("Yes\n");exit(0);}
    printf("No\n");
    return 0;
}
