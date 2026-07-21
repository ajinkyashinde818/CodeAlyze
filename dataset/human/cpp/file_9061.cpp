#include <bits/stdc++.h>
using namespace std;
static const int MAX_N = 60;
static const int MAX_M = 60;
char a[MAX_N][MAX_N];
char b[MAX_M][MAX_M];
int n,m;
int a_tate,a_yoko,b_tate,b_yoko;

bool isMatch(int y,int x){
    for(int i=y;i<y+b_tate;i++){
        for(int j=x;j<x+b_yoko;j++){
            if(a[i][j]!=b[i-y][j-x])
                return false;
        }
    }
    return true;
}


int main()
{
    cin>>n>>m;
    a_tate = n;
    b_tate = m;
    //input a
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            a[i][j] = s[j];
        }
        a_yoko = s.size();
    }
    //input b
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            b[i][j] = s[j];
        }
        b_yoko = s.size();
    }
    //judge
   // cout<<"a_tate : "<<a_tate<<endl;
   // cout<<"a_yoko : "<<a_yoko<<endl;
   // cout<<"b_tate : "<<b_tate<<endl;
   // cout<<"b_yoko : "<<b_yoko<<endl;

    for(int i=0;i<a_tate-b_tate+1;i++){
        for(int j=0;j<a_yoko-b_yoko+1;j++){
            //match?
            bool flag = isMatch(i,j);
            if(flag){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
