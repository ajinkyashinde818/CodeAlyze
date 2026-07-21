#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=400000;
int n;
int left[Maxn+5],right[Maxn+5];
int a[Maxn+5],b[Maxn+5];
struct Segment{
	int left,right;
	friend bool operator <(Segment a,Segment b){
		return a.left<b.left;
	}
}seg[Maxn+5];
int len;
int f[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(left[a[i]]==0){
			left[a[i]]=i;
		}
		right[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i+n]=b[i];
	}
	for(int i=1;i<=(n<<1);i++){
		if(left[b[i]]==0){
			continue;
		}
		seg[++len].left=i-right[b[i]]+1;
		seg[len].right=i-left[b[i]]+1;
	}
	for(int i=1;i<=len;i++){
		if(seg[i].left<1){
			f[1]++;
		}
		else{
			f[seg[i].left]++;
		}
		if(seg[i].right<0){
			f[1]--;
		}
		else{
			f[seg[i].right+1]--;
		}
	}
	for(int i=1;i<=n;i++){
		f[i]+=f[i-1];
	}
	int pos=-1;
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			pos=i;
			break;
		}
	}
	if(pos==-1){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=pos;i<pos+n;i++){
		printf("%d ",b[i]);
	}
	puts("");
	return 0;
}
