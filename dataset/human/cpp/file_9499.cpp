#include <iostream>
#include <string>

using namespace std;

int main(){
    string A[50];
    string B[50];
    int N;  cin >> N;
    int M;  cin >> M;
    for(int i = 0;i < N;i++)cin >> A[i];
    for(int i = 0;i < M;i++)cin >> B[i];

    for(int i = 0;i <= N-M;i++){//スタートする行
      for(int j = 0;j <= N-M;j++){//スタートする列
        bool flag = true;
        for(int k = 0;k < M;k++){//走査用
          if(A[i+k].substr(j,M) != B[k])flag = false;
        }
        if(flag){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }

    cout << "No" << endl;





}
