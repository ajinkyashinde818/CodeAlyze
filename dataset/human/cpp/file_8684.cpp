/*
tags:[贪心][排序][预处理]
贪心地选取一些连续的夏日，在这些连续的夏日里使用冬胎。
a[i]: 第i个冬日，出现在第几天。
b[i] = a[i+1] - a[i] － 1表示两个相邻的冬日之间有多少个连续的夏日。
显然，我们希望连续的夏日时间越短越好，故对b从小到大排序。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int NICO = 200000 + 10;
int n, m;
char s1[60][60],s2[60][60]; 
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) scanf("%s",s1[i]);
    for(int i=0;i<m;i++) scanf("%s",s2[i]);
    int ok = 0;
    for(int i=0;i<=n-m;i++)
    {
        for(int j=0;j<=n-m;j++)
        {
            int ac = 1;
            for(int a=i;a<i+m;a++)
            {
                for(int b=j;b<j+m;b++)
                {
                    if(s1[a][b] != s2[a-i][b-j])
                    {

                        ac = 0;
                    }
                }
            }
            if(ac) ok = 1;
        }
    }
    cout << (ok?"Yes":"No") << endl;
}
