#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll n,m;
    cin >> n >> m;
    auto a = vector<string>(n);
    auto b = vector<string>(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    queue<pair<int,int> > q;
    for(int i=0;i+m-1<n;i++){
       auto s=string::npos;
       do{
            s=a[i].find(b[0],s+1);
            if(s!=string::npos) q.push(make_pair(i,s));
       }while(s+b[0].size()<=a[i].size()&&s!=string::npos); 
    }
    
    
    bool f = false;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        f = false;
        for(int i=u.first;i-u.first<m&&i<n;i++){
               int j = i-u.first;
               if(j>=m){
                   f = false;
                   break;
               }
               if(a[i].substr(u.second,b[j].size()).find(b[j])==string::npos){
                    f= false;
                    break;
               }
               f=true;
        }
        if(f)break;
    }
    
    cout << (f?"Yes":"No");
    
    return 0;
}
