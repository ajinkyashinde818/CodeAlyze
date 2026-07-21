#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v1(n,vector<char>(n,0));
    vector<vector<char>>v2(m,vector<char>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v1[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v2[i][j];
        }
    }
    bool yes=0;
    for(int i=0;i<=n-m;i++)
    {
        for(int j=0;j<=n-m;j++)
        {
            bool no=0;
            for(int k=0;k<m;k++)
            {
                for(int p=0;p<m;p++)
                {
                    if(v1[i+k][j+p]!=v2[k][p]){
                        no=1;
                        break;
                    }
                }
                if(no){
                    break;
                }
            }
            if(!no){
                yes=1;
                break;
            }
        }
        if(yes){
            break;
        }
    }
    if(yes){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
