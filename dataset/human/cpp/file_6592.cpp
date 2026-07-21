#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1e9+7;
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}
int n,ans=1,dep;
bool d[maxn];
char s[maxn];
vector<char> st;

int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=2*n;i++){
        if(st.empty()){
            if(s[i]!='B')return !printf("0");
            st.push_back('B');
            dep++;
            continue;
        }
        if(s[i]!=st.back()){
            st.push_back(s[i]);
            dep++;
            continue;
        }
        ans=mul(ans,dep);
        dep--;
        st.pop_back();
    }
    for(int i=2;i<=n;i++)
        ans=mul(ans,i);
    printf("%d\n",st.empty()?ans:0);
}
/*
    Good Luck
        -Lucina
*/
