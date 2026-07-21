#include<iostream>

using namespace std;

class ButCoder{
    public:
        int n, r;

        int Rating(int n, int r)
        {
            int rat = r;
            if(n < 10)
            {
                rat = 100 * (10 - n);
                rat += r;
            }

            return rat;
        }

};

int main()
{

    ButCoder obj;

    cin >> obj.n >> obj.r;

    cout << obj.Rating(obj.n, obj.r) << endl;
    return 0;
}
