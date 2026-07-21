#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a[1010];

int main(){
    scanf("%d",&n);
    int t = sqrt(2*n+0.5);
    if(t*(t+1)==2*n){
        printf("Yes\n%d\n",t+1);
        int cnt = 1;
        for(int i=1;i<=t;i++){
            for(int j=1;j<=i;j++){
                a[i].push_back(cnt);
                if(j==i)a[t+1].push_back(cnt);
                else
                a[j].push_back(cnt);
                cnt++;
            }
        }
        for(int i=1;i<=t+1;i++){
            printf("%d",t);
            for(int j=0;j<a[i].size();j++){
                printf(" %d",a[i][j]);
            }
            printf("\n");
        }
    }
    else printf("No\n");
}
