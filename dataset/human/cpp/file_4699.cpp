#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int Rrate,num;
    int Frate;
    cin >> num;
    cin >> Frate;

    if(num>=10){
        Rrate = Frate;
    }
    else{
        Rrate = Frate+100*(10-num);
    }

    cout << Rrate << endl;
}
