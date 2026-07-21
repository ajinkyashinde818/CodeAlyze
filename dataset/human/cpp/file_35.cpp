#include<iostream>
#include<algorithm>

using namespace std;
int main(){
int N;
int R,G,B;
cin >>R >>G>>B>>N;
int answer=0;
int a[3];
a[0]=R;
a[1]=G;
a[2]=B;
long  dp[4][3010];
dp[0][0]=1;
for(int i=0;i<3;++i){
    for(int j=0;j<=N;++j){
        dp[i+1][j]=dp[i][j];
        if(j>=a[i]){
            for(int l=1;l<=j/a[i];l++)
            dp[i+1][j]+=dp[i][j-a[i]*l];
        }
    }
}
cout <<dp[3][N]<<endl;


  return 0;
}
