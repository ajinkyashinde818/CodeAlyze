#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numa, numb;
    cin >> numa >> numb;

    string A[51];
    string B[51];

    for(int i=0;i<numa;i++){
        cin >> A[i];
    }
    for(int i=0;i<numb;i++){
        cin >> B[i];
    }

    for(int i=0;i<numa-numb+1;i++){
        for(int j=0;j<numa-numb+1;j++){
            bool judge = true;
            for(int k=0;k<numb;k++){
                if(A[i+k].compare(j,numb,B[k])!=0){
                    judge = false;
                }
            }
            if(judge){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
