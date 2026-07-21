#include<iostream>
#include<algorithm>


using namespace std;

int main(int argc, char const *argv[])
{

    long long  A, B;

    cin>>A>>B;
    if (A>=10)
    {
        cout << B << endl;
    }else
    {
        cout << B + (10-A) * 100 << endl;
    }
    
    
    return 0;
}
