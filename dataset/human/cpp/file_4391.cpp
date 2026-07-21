#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=100006;
int a[maxn],b[maxn];
int n;
bool eq(){
  for(int i=1;i<=n;++i)if(a[i]!=b[i])return false;
  return true;
}
int c[maxn],d[maxn];
bool nosolu(){
  int pt=1;
  for(int i=1;i<=n+1;++i){
    if(pt<=n&&c[i]==d[pt])++pt;
  }
  return pt<=n;
}
int seq[maxn];
int res=0;
map<int,int> cnt1,cnt2;
void check(){
  int tot=0;
  for(int i=1;i<=n;++i){
    if(a[i]!=b[i])cnt1[a[i]]++,cnt2[b[i]]++;
  }
  int val=-1,VAL;
  for(int i=1;i<=n;++i){
    if(a[i]!=b[i]){
      if(cnt1[a[i]]>cnt2[a[i]]){
	val=a[i];
      }
      if(cnt1[b[i]]<cnt2[b[i]]){
	VAL=b[i];
      }
    }
  }
  if(val!=-1){//printf("%d %d\n",val,VAL);
    for(int i=1;i<=n;++i){
      if(b[i]==VAL){
	b[i]=val;
	if(val==a[i])res++;
	break;
      }
    }
  }
}
int ufs[maxn];
int find(int x){
  return x==ufs[x]?x:ufs[x]=find(ufs[x]);
}
bool cmp1(const int &x,const int &y){
  return a[x]<a[y];
}
bool cmp2(const int &x,const int &y){
  return b[x]<b[y];
}
void link(int a,int b){
  ufs[find(a)]=find(b);
}
int work(){
  check();
  bool flag=true;
  for(int i=1;i<=n;++i)if(a[i]!=b[i])flag=false;
  if(flag)return 1;
  int cnt=0;
  for(int i=1;i<=n;++i)if(a[i]!=b[i])seq[++cnt]=i;
  sort(seq+1,seq+cnt+1,cmp1);
  int old=-1,tot=0;
  for(int i=1;i<=cnt;++i){
    if(old!=a[seq[i]]){
      old=a[seq[i]];++tot;
    }
    a[seq[i]]=tot;
  }
  old=-1;tot=0;
  sort(seq+1,seq+cnt+1,cmp2);
  for(int i=1;i<=cnt;++i){
    if(old!=b[seq[i]]){
      old=b[seq[i]];++tot;
    }
    b[seq[i]]=tot;
  }
  for(int i=1;i<=tot;++i)ufs[i]=i;
  for(int i=1;i<=cnt;++i){
    link(a[seq[i]],b[seq[i]]);
  }
  int ans=0;
  for(int i=1;i<=tot;++i)if(ufs[i]==i)ans++;
  return ans+res;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i)scanf("%d",a+i);
  for(int i=1;i<=n;++i)scanf("%d",b+i);
  for(int i=1;i<=n;++i)c[i]=a[i],d[i]=b[i];
  c[n+1]=0;for(int i=1;i<=n;++i)c[n+1]^=c[i];
  int tmp=c[n+1];
  sort(d+1,d+n+1);sort(c+1,c+n+2);
  if(eq())printf("0\n");
  else{
    if(nosolu())printf("-1\n");
    else{
      int cnt=0;bool flag=false;
      for(int i=1;i<=n;++i){
	if(a[i]!=b[i]){
	  cnt++;if(b[i]==tmp)flag=true;
	}
      }
      if(flag)printf("%d\n",cnt+work()-1);
      else printf("%d\n",cnt+work());
    }
  }
  return 0;
}
