#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[59][59], b[59][59];

bool check(int t, int l){
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            if(a[t+i][l+j] != b[i][j]) return false;
    return true;
}

int main(){
    scanf("%d %d ",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s", a[i]);
    for(int i=0; i<m; i++)
        scanf("%s", b[i]);

    for(int i=0; i < n-m+1; i++)
        for(int j=0; j < n-m+1; j++)
            if(check(i,j)){
                printf("Yes\n");
                return 0;
            }

    printf("No\n");
    return 0;
}
