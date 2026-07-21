/*|In The Name of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

int n;
int m;
char A[100][100];
char B[100][100];

bool can(int I , int J){
     int JJ = J;
     for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if(A[I][J] == B[i][j]){
               if(J == n){
                  I++;
                  J = JJ;
               } else {
                  J++;
               }
            } else {
               return 0;
            }
        }
     }
     return 1;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> B[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(can(i , j)){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}
