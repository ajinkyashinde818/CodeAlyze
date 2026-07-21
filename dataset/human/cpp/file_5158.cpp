#include<bits/stdc++.h>
using namespace std;

int InterRating(int x, int y){
    if(x<10){
        return y+100*(10-x);
    }else{
        return y;
    }
}

int main(){
    int N,R; cin >> N >> R;
    cout << InterRating(N,R) << endl;
}
