#include<bits/stdc++.h>
using namespace std;
int n,a[200010],c[200010],B[200010],A[200010],b[200010],fa[200010],s[200010];
int ans;
int w,Sum,x,y,tot;
inline int read(){
    char ch;
    bool f=false;
    int res=0;
    while (((ch=getchar())<'0'||ch>'9')&&ch!='-');
    if (ch=='-')
        f=true;
    else 
        res=ch-'0';
    while ((ch=getchar())>='0'&&ch<='9')
        res=(res<<3)+(res<<1)+ch-'0';
    return f?~res+1:res;
}
int find(int x){
    if (fa[x]==x)
        return x;
    int y=find(fa[x]);
    fa[x]=y;
    return fa[x];
}
int main(){
    //freopen("duliu.in","r",stdin);
	//freopen("duliu.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        x^=a[i];
        A[i]=a[i];
    }
    a[n+1]=x;
    A[n+1]=x;
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        y^=b[i];
        B[i]=b[i];
    }
    b[n+1]=y;
    B[n+1]=y;
    n++;
    sort(B+1,B+1+n);
    sort(A+1,A+1+n);    
    for (int i=1;i<=n;i++)
        if (A[i]!=B[i]){
            printf("-1\n");
            return 0;
        }
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]||i==n){
            c[++tot]=a[i];
            c[++tot]=b[i];
            if (i<n){
                ans++;
            }
        }
    if (ans==0){
        printf("0\n");
        return 0;
    }
    sort(c+1,c+tot+1);
    tot=unique(c+1,c+tot+1)-c-1;
    
    for (int i=1;i<=tot;i++)
        fa[i]=i;
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]){
            a[i]=lower_bound(c+1,c+tot+1,a[i])-c;
            b[i]=lower_bound(c+1,c+tot+1,b[i])-c;
            if (!s[a[i]])
                s[a[i]]=1;
            if (!s[b[i]])
                s[b[i]]=1;
            fa[find(a[i])]=find(b[i]);
        }
    for (int i=1;i<=tot;i++)
        if (fa[i]==i)
            Sum++;
    printf("%d\n",ans+Sum-1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
