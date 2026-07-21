#include <bits/stdc++.h>
using namespace std;

int main(){

int R;
int G;
int B;
int N;

cin >> R >> G >> B >> N;

int i = -1;
int j = -1;
int k = -1;
int times = 0;

while (true){
    i += 1;
    if (i*R > N){
        i = -1;
        break;
    }
        
    while (true){          
        j += 1;
        if ((i*R + j*G) > N){
            j = -1;
            break;
        }
        if ((N - i*R - j*G) % B == 0){
          times++;
        }
    }
}
                
cout << times << endl;
}
