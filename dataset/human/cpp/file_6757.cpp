#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    vector<int> a(n),b(n);
    vector<int> cnt(n+1);
    vector<vector<int>> p(n+1);
    int cnt_a[n+1]={};
    int cnt_b[n+1]={};
    int r[n+1]={};
    int now[n+1]={};
    int sum[n+1]={};
    int rum[n+1]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt_a[a[i]]++;
        //rum[a[i]]++;
        cnt[a[i]]++;
        p[a[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        cnt_b[b[i]]++;
        //sum[b[i]]++;
        cnt[b[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(cnt[i] > n){
            cout << "No\n";
            return 0;
        }
    }
    priority_queue<array<int,2>> pq1;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq2;
    for(int i=1;i<=n;i++){
        if(n-cnt[i] == n)continue;
        pq1.push({n-cnt[i],i});
        pq2.push({n-cnt[i],i});
        now[i] = n - cnt[i];
    }
    for(int i=0;i<n;i++)b[i] = 0;
    while(pq2.size()){
        array<int,2> t = pq2.top();
        //cerr << t[0] << " " << t[1] << endl;
        pq2.pop();
        if(t[0] != now[t[1]])continue;
        if(sum[t[1]] == cnt_b[t[1]])continue;
        vector<array<int,2>> v;
        while(pq1.size()){
            // cerr<<"a" << endl;
            array<int,2> y = pq1.top();
            pq1.pop();
            if(y[0] != now[y[1]])continue;
            if(rum[y[1]] == cnt_a[y[1]])continue;
            if(y[1] == t[1]){
                v.push_back(y);
                continue;
            }
            //cerr << "y " << y[0] << " " << y[1] << endl;

            b[p[y[1]][r[y[1]]]] = t[1];
            r[y[1]]++;
            now[y[1]]++;
            now[t[1]]++;
            sum[t[1]]++;
            rum[y[1]]++;
            pq2.push({t[0]+1, t[1]});
            pq1.push({t[0]+1, t[1]});
            pq1.push({y[0]+1, y[1]});
            pq2.push({y[0]+1, y[1]});
            break;
        }
        for(auto i:v){
            pq1.push(i);
        }
    }
    cout << "Yes\n";

    for(int i=0;i<n;i++){
        cout << b[i] << " ";
        assert(a[i] != b[i]);
    }
    cout << endl;

}
