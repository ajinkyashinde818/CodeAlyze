#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numr, numg, numb, num;
    cin >> numr >>numg >> numb >> num;

    int count =0 ;
    int sum , sumtwo;

    for(int i=0;i<=num/numr;i++){
        sum = num - numr*i;
        for(int j=0;j<=sum/numg;j++){
            sumtwo = sum - j*numg;
            if(sumtwo%numb==0){
                count ++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
