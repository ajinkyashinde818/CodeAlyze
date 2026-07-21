#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    int N; 
    cin >> N;
    if(N==1){
        cout<<"Yes"<<endl;
        cout<<2<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    for(int n=2;n*(n+1)/2<=N;n++){
        if(N != n*(n+1)/2) continue;

        cout<<"Yes"<<endl;
        cout<<(n+1)<<endl;

        cout<<n;
        for(int i=0;i<n;i++){cout<<" "<<(0*(n-1)+1+i);}
        cout<<endl;
        cout<<n;
        for(int i=0;i<n;i++){cout<<" "<<(1*(n-1)+1+i);}
        cout<<endl;
        cout<<n;
        for(int i=0;i<n-1;i++){cout<<" "<<(2*(n-1)+1+i);}
        cout<<" "<<1;
        cout<<endl;

        vector<vector<int>> l(n-2, vector<int>());
        for(int i=1;i<n-1;i++){
            l.at(i-1).push_back(0*(n-1)+1+i);
            l.at(i-1).push_back(1*(n-1)+1+i);
            l.at(i-1).push_back(2*(n-1)+1+i);
        }
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                l.at(i-1).push_back(3*(n-1)+(j-1)+(n-3)*(i-1)-i*(i-1)/2);
                l.at(j-1).push_back(3*(n-1)+(j-1)+(n-3)*(i-1)-i*(i-1)/2);
            }
        }
        for(int i=1;i<n-1;i++){
            cout<<l.at(i-1).size();
            for(auto v: l.at(i-1)){
                cout<<" "<<v;
            }
            cout<<endl;
        }

        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
