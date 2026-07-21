#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string s1[n],s2[m];
    for(int i=0;i<n;i++)cin>>s1[i];
    for(int i=0;i<m;i++)cin>>s2[i];
    bool flag=false;
    for(int x1=0;x1<=n-m;x1++){
        for(int y1=0;y1<=n-m;y1++){
            bool match=true;
            for(int x=0;x<m;x++){
                for(int y=0;y<m;y++){
                    if(s1[x+x1][y+y1]!=s2[x][y])match=false;
                }
            }
            if(match)flag=true;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
