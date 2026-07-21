using namespace std;
#include <iostream>
#include <stdio.h>
#include <sstream>      // std::ostringstream
#include <math.h>
int main()
{
    string str_r,str_g,str_b,str_n;
    cin >> str_r >> str_g >> str_b >> str_n;
    int r = stoi(str_r);
    int g = stoi(str_g);
    int b = stoi(str_b);
    int n = stoi(str_n);

    int count = 0;
    for(int i=0;i<=n;i+=r){
        for(int j=0;j<=n;j+=g){
            int v = i+j;
            if(n>=v&&(n-v)%b==0){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
