#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int mod=1e9+7;
int n;
int a[maxn],b[maxn];
vector<int>p1,p2;
bool vis[maxn];
int main(){
    scanf("%d",&n);

    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)scanf("%d",&b[i]);

    sort(b+1,b+1+n,greater<int>());


    int st=-1,len=0,val=-1;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            val=b[i];
            if(st==-1)st=i;
            len++;
            p2.push_back(b[i]);
        }
    }
    if(st==-1){
        printf("Yes\n");
        for(int i=1;i<=n;i++)printf("%d ",b[i]);
        printf("\n");
        return 0;
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    if(a[i]!=b[i]&&cnt<len&&a[i]!=val&&b[i]!=val){
        cnt++;
     //   printf("a[%d]=%d\n",i,a[i]);
        p1.push_back(b[i]);
        vis[i]=1;
    }

    if(cnt<len){
        printf("No\n");
    }
    else{
     printf("Yes\n");

     int pos1=-1,pos2=-1;
     for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            b[i]=p1[++pos1];
        }
        else if(vis[i]){
            b[i]=p2[++pos2];
        }
     }

     for(int i=1;i<=n;i++)printf("%d ",b[i]);
        printf("\n");

    }
    return 0;
}
