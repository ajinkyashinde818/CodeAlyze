#include<bits/stdc++.h>
using namespace std;

int T,D;
int ta,tb;
int da,db;

int main(){
    cin>>T>>D;
    cin>>ta>>tb;
    cin>>da>>db;

    double ans=INT_MAX;


    for(int i=0;i*da<=D;i++){
        for(int j=0;j*db<=D-i*da;j++)if(i||j){
            ans=min(ans,fabs(T-1.0*(ta*i*da+tb*j*db)/(i*da+j*db)));
        }
    }


    printf("%.6lf\n",ans);
    return 0;
}
