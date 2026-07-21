#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,data[200001]={};
    stack<int>s;
    cin>>n>>m;
    for(int i=n;i>=1;--i) s.push(i);
    for(int i=0;i<m;++i){
	cin>>x;
	s.push(x);
    }
    for(int i=1;i<=n;++i){
	if(data[s.top()]==0){
	    cout<<s.top()<<endl;
	    data[s.top()]=1;
	}else --i;
	s.pop();
    }
    return 0;
}
