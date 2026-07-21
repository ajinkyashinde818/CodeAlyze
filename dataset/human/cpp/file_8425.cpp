#include<bits/stdc++.h>

using namespace std;

int main(){
        string a[100];
        string b[100];
        int N, M;
        cin>>N>>M;
        for(int i=0;i<N;i++){
                cin>>a[i];
        }
        for(int i=0;i<M;i++){
                cin>>b[i];
        }
        bool flag=false;
        for(int i=0;i<=N-M;i++){
                for(int j=0;j<=N-M;j++){
                        int cnt=0;
                        for(int k=0;k<M;k++){
                                for(int h=0;h<M;h++){
                                        if(a[i+k][j+h]==b[k][h]){
                                                cnt++;
                                        }
                                }
                        }
                        if(cnt==M*M){
                                flag=true;
                        }
                }
        }
        if(flag){
                cout<<"Yes"<<endl;
        }
        else{
                cout<<"No"<<endl;
        }
        return 0;
}
