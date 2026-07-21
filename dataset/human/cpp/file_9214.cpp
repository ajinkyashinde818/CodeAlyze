#include<iostream>
#include<cstdio>
using namespace std;
class B{
    public:
        void solve(int n,int m){
            char a[n][n];
            char b[m][m];
            for(int i=0;i<n;i++)scanf("%s",a[i]);
            for(int i=0;i<m;i++)scanf("%s",b[i]);
            int match=0;
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    bool flag=true;
                    if(k+m-1>=n||l+m-1>=n)continue;
                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            if(a[i+k][j+l]!=b[i][j])flag=false;
                        }
                    }
                    if(flag)match++;
                }
            }
            if(match!=0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
};
int main(){
    B inst;
    int n,m;
    cin>>n>>m;
    inst.solve(n,m);
    return 0;
}
