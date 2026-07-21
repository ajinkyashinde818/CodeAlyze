#include<iostream>
#include<string>
using namespace std;

void Scan(string* a,int n){
    for(int i=0;i<n;i++)
        cin>>a[i];
}

bool Mat(string* a,string* b,int x,int y,int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(a[x+i][y+j]!=b[i][j]) return false;
        }
    }
    return true;
}

void Solve(string* a,string* b,int n,int m){
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            if(Mat(a,b,i,j,m)){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
}

int main(){
    int n,m;
    string a[55],b[55];
    while(cin>>n>>m){
        Scan(a,n);
        Scan(b,m);
        Solve(a,b,n,m);
    }
    return 0;
}
