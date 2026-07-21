//Problem D
#include<bits/stdc++.h>
using namespace std;

int n,k,s,t,x;
vector<int>e[100005];
int main(){
    scanf("%d",&n);
    //if(n==3)printf("Yes\n3\n2 1 2\n2 3 1\n2 2 3");else printf("No");
    t=n<<3|1;s=sqrt(t);if(s*s!=t){printf("No");return 0;}
    ++s;if(s&1){printf("No");return 0;}k=s>>1;
    for(int i=1;i<k;i++)for(int j=i+1;j<=k;j++)e[i].push_back(++x),e[j].push_back(x);
    printf("Yes\n%d",k);
    for(int i=1;i<=k;i++){
        printf("\n%d",e[i].size());
        for(int j=0;j<e[i].size();j++)printf(" %d",e[i][j]);
    }
    return 0;
}
