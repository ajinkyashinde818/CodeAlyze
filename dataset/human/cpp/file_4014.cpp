#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double x[2000],y[2000],r[2000];
double eps = 1e-9;
double dist(int i,int j){
    double dx=x[i]-x[j], dy=y[i]-y[j];
    double d = dx*dx + dy*dy;
    double dr = r[i]*r[i] + 2*r[i]*r[j] + r[j]*r[j];
    if(d + eps <= dr) return 0;
    return sqrt(d) - r[i]-r[j];
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    double a,b,c,d;
    cin>>a>>b>>c>>d;
    int n;
    cin>>n;
    x[0] = a, y[0] = b, r[0] = 0;
    x[n+1] = c, y[n+1] = d, r[n+1] = 0;
    for(int i=1;i<=n;i++){
        double a,b,c;
        cin>>a>>b>>c;
        x[i]=a,y[i]=b,r[i]=c;;
    } 
    n += 2;
    double dp[n][n]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            else dp[i][j] = 1e15;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = min(dp[i][j],dist(i,j));
        }
    }
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
    }
    cout << dp[0][n-1] << endl;


}
