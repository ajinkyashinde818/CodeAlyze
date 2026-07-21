#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string a[100],b[100];
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
    
	int N,M;
    string result="No";
	cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<M;i++){
        cin >> b[i];
    }
    for(int ii=0;ii<=N-M;ii++){
        for(int ij=0;ij<=N-M;ij++){
            bool judge=true;
            for(int ji=0;ji<M;ji++){
                for(int jj=0;jj<M;jj++){
                    if(a[ii+ji][ij+jj]!=b[ji][jj]) judge=false;
                }
            }
            if(judge) result="Yes";
        }
    }
    cout << result << "\n";
}
