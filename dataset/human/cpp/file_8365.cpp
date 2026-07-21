#include <bits/stdc++.h>
using namespace std;

int n,m;
char A[55][55], B[55][55];

bool Check(int i,int j){
    for(int x = i, cnt1 = 1; cnt1 <= m; x++, cnt1++)
        for(int y = j, cnt2 = 1; cnt2 <= m; y++, cnt2++)
            if(A[x][y] != B[cnt1][cnt2]) return false;
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%s", A[i] + 1);
    for(int i = 1; i <= m; i++) scanf("%s", B[i] + 1);

    //Check
    for(int i = 1; i + m - 1 <= n; i++){
        for(int j = 1; j + m - 1 <= n; j++){
           if(Check(i, j)){
            printf("Yes\n");
            return 0;
           }
        }
    }
    printf("No\n");
    return 0;
}
