#include<iostream>
#include<string>

using   namespace std;

int main(){
    int R,G,B,N,count=0;
    scanf("%d %d %d %d",&R,&G,&B,&N);

    for(int i=N/R;i>=0;i--){
        for(int j=(N-i*R)/G;j>=0;j--){
            if((N-i*R-j*G)%B==0)
                count++;
        }
    }
    cout <<count << endl;
}
