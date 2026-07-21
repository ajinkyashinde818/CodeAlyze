#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int n;
long long int l;
string s[N+87];
string t="";
long long int ans=0;
int now=0;
int pre=0;

inline long long int lowbit(long long int x){return x&(-x);}

void dfs(int i){
    if(now<n&&t==s[now]){
        now++;
        pre=0;
        while(now<n&&pre<t.size()&&pre<s[now].size()&&t[pre]==s[now][pre])pre++;
    }
    else if(now==n||pre<i){
        ans=ans^lowbit(l+1-i);
    }
    else{
        t=t+"0";
        if(pre==i&&i<t.size()&&i<s[now].size()&&t[i]==s[now][i])pre++;
        dfs(i+1);
        if(pre==i+1&&i<t.size()&&i<s[now].size()&&t[i]==s[now][i])pre--;
        t.erase(i);

        t=t+"1";
        if(pre==i&&i<t.size()&&i<s[now].size()&&t[i]==s[now][i])pre++;
        dfs(i+1);
        if(pre==i+1&&i<t.size()&&i<s[now].size()&&t[i]==s[now][i])pre--;
        t.erase(i);
    }
}

int main(){
    cin>>n>>l;
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s,s+n);

    dfs(0);
    if(ans==0)cout<<"Bob\n";
    else cout<<"Alice\n";
}
