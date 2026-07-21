#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
 
    int a=(n+1)/2-1;
    vector<int>ans;
    if(n&1){
        int ma;
        double val=-114514;
        for(int i=0;i<=m;i++){
            int x;
            if(i<=m/2){
                x=(n+1)/2*i+n/2*m;
            }
            else{
                x=(n+1)/2*i;
            }
            double y=(i-1.0*x/n);
            if(val<y){
                val=y;
                ma=i;
            }
        }
 
        if(ma<=m/2){
            for(int i=0;i<(n+1)/2;i++)ans.push_back(ma);
            for(int i=0;i<n/2;i++)ans.push_back(m);
        }
        else{
            for(int i=0;i<n/2;i++)ans.push_back(0);
            for(int i=0;i<(n+1)/2;i++)ans.push_back(ma);
        }
    }
 
    else{
        int ma1,ma2;
        double val=0;
        for(int i=0;i<=m;i++){
            for(int j=i;j<=m;j++){
                int x;
                if(i+j<=m*2){
                    x=i*n/2+j+(n-1)/2*m;
                }
                else{
                    x=i+j*n/2;
                }
                double y=fabs(1.0*(i+j)/2-1.0*x/n);
                if(val<y){
                    val=y;
                    ma1=i;
                    ma2=j;
                }
            }
        }
 
        if(ma1+ma2<=m*2){
            for(int i=0;i<n/2;i++)ans.push_back(ma1);
            ans.push_back(ma2);
            for(int i=0;i<(n-1)/2;i++)ans.push_back(m);
        }
        else{
            for(int i=0;i<(n-1)/2;i++)ans.push_back(0);
            ans.push_back(ma1);
            for(int i=0;i<n/2;i++)ans.push_back(ma2);
        }
    }
 
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
