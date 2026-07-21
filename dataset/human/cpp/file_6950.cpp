#include <iostream>
#include <set>
#include <vector>
using namespace std;
int a[200010],b[200010],c[200010],cnt[2][200010] = {};
vector<int> v[200010],u[200010],w[200010],wa,wb;
int main(){
    int i,j,n; cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++) cin >> b[i];
    for(i=0;i<n;i++) cnt[0][a[i]]++,cnt[1][b[i]]++;
    for(i=1;i<=n;i++){
        if(cnt[0][i] + cnt[1][i]>n){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(i=0;i<n;i++) v[a[i]].push_back(i),u[b[i]].push_back(i);
    for(i=1;i<=n;i++){
        if(cnt[0][i] && cnt[1][i]){
            w[cnt[0][i] + cnt[1][i]].push_back(i);
        }
    }
    for(i=0;i<n;i++){
        if(!cnt[1][a[i]]) wa.push_back(a[i]);
        if(!cnt[0][b[i]]) wb.push_back(b[i]);
    }
    w[0].push_back(0);
    int f = n,s = n;
    //cout << wa.size() << " " << wb.size() << endl;
    for(i=0;i<n;i++){
        while(w[f].size()==0) f--;
        int k,l; bool f0 = false,f1 = false;
        if(f==0) k = wa.back(),wa.pop_back();
        else k = w[f].back(),w[f].pop_back(),f0 = true;
        while(w[s].size()==0) s--;
        if(s==0) l = wb.back(),wb.pop_back();
        else l = w[s].back(),w[s].pop_back(),f1 = true;
        int ind1,ind2;
        if(v[k].size() && u[l].size()){
            ind1 = v[k].back(); v[k].pop_back(); 
            ind2 = u[l].back(); u[l].pop_back();
        }else{
            cout << " a " << endl;
            cout << i << " " << f << " "<< s << endl;
            cout << k << " " << l << endl;
            for(int j:wa) cout << j << " ";
            cout << endl;
            for(int j:wb) cout << j << " ";
            cout << endl;
            exit(1);
        }
        //cout << k << " "<< l << " b " << ind1 << " " << ind2 << endl;
        c[ind1] = b[ind2];
        if(v[k].size() && u[k].size()){
            w[f - 1].push_back(k); 
        }else{
            if(f0) for(j=0;j<v[k].size();j++) wa.push_back(k);
            if(f0) for(j=0;j<u[k].size();j++) wb.push_back(k);
        }
        if(v[l].size() && u[l].size()){
            w[s - 1].push_back(l);
        }else{
            if(f1) for(j=0;j<v[l].size();j++) wa.push_back(l);
            if(f1) for(j=0;j<u[l].size();j++) wb.push_back(l);
        }
    }
    for(i=0;i<n;i++) cout << c[i] << " ";
    cout << endl;
}
