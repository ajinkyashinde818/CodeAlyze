#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, A[101000], B[101000];
int X[201000], cnt, C[201000], res;
vector<int>E[201000];
bool v[201000];
void DFS(int a){
    int i;
    v[a]=true;
    for(i=0;i<E[a].size();i++)if(!v[E[a][i]])DFS(E[a][i]);
}
int main(){
    int i, s = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        s^=A[i];
    }
    A[n] = s;
    s = 0;
    for(i=0;i<n;i++){
        scanf("%d",&B[i]);
        s^=B[i];
    }
    B[n] = s;
    for(i=0;i<=n;i++){
        X[++cnt] = A[i];
        X[++cnt] = B[i];
    }
    sort(X+1,X+cnt+1);
    for(i=0;i<=n;i++){
        A[i] = lower_bound(X+1, X+cnt+1, A[i])-X;
        B[i] = lower_bound(X+1, X+cnt+1, B[i])-X;
    }
    for(i=0;i<=n;i++)C[A[i]]++,C[B[i]]--;
    for(i=1;i<=cnt;i++){
        if(C[i]){
            printf("-1\n");
            return 0;
        }
    }
    for(i=0;i<=n+1;i++){
        if(A[i]!=B[i])E[A[i]].push_back(B[i]), res++;
    }
    for(i=1;i<=cnt;i++){
        if(!v[i] && !E[i].empty()){
            DFS(i);
            res++;
        }
    }
    if(!E[A[n]].empty())res--;
    if(A[n]!=B[n])res--;
    printf("%d\n",res);
}
