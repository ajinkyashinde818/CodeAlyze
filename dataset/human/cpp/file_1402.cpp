#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(int argc, char** argv) {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    if (argc == 2 && atoi(argv[1]) == 123456789)
        freopen("d:\\code\\cpp\\stdin", "r", stdin);

    int n;
    scanf("%d", &n);
    int k=1;
    while(k*(k-1)/2 < n)
        k++;
    if (k*(k-1)/2 == n){
        printf("Yes\n");
        printf("%d\n", k);

        vector<vector<int>> Ss(k);
        int row1 = 0, row2 = 1;
        const int m = k-1;
        for(int i=1; i<=n; i++){
            if (Ss[row1].size()==m){
                row1++;
                row2 = row1+1;
            }
            Ss[row1].push_back(i);
            Ss[row2++].push_back(i);
        }

        for(int kk=0;kk<k; kk++) {
            printf("%d ",k-1);
            for (int x : Ss[kk])
                printf("%d ", x);
            printf("\n");
        }

    }
    else{
        printf("No\n");
    }

    return 0;
}
