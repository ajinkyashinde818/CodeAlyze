#include<iostream>


using namespace std;
int hantei(int N);
int main(){
    int kosuu,m,N;
    cin >> N;
    if(hantei(N)==0){
        cout << "No";
        return 0;
    }
    kosuu=hantei(N);
    cout << "Yes\n";
    cout << kosuu+1 << "\n";
    for(int i=1;i<=kosuu+1;i++){
        cout << kosuu;
        for(int j=(i-1)*(i-2)/2+1;j<=i*(i-1)/2;j++){
            cout << " ";
            cout << j;
        }
        if(i==kosuu+1)break;
        cout << " ";
        cout << i*(i+1)/2;
        m=i*(i+1)/2;
        for(int j=i;j<=kosuu-1;j++){
            cout <<" ";
            cout << m+j;
            m+=j;
        }
        cout << "\n";
    }
    return 0;
}

int hantei(int N){
    for(int i=1;;i++){
        if(i*(i+1)==2*N){
            return i;
        } else if(i*(i+1)>2*N){
            return 0;
        }
    }
    return -1;
}
