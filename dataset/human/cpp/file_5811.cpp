#include <limits>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct sushi {
    int64_t x;
    int64_t v;
    int64_t f_r;
    int64_t f_l;
    int64_t f_r_max;
    int64_t f_l_max;
};

int main()
{
    int64_t N,C;
    cin >> N >> C;

    vector<sushi> ss;
    ss.reserve(N);

    for(int i = 0; i < N; ++i)
    {
        sushi s;
        cin >> s.x >> s.v;
        ss.push_back(s);
    }   
    {
        int64_t vsum = 0;
        int64_t rmax = 0;
        for(int i = 0; i < N; ++i)
        {
            vsum += ss[i].v;
            ss[i].f_r = vsum - ss[i].x;
            ss[i].f_r_max = rmax = max(ss[i].f_r, rmax);
        }
    }
    {
        int64_t vsum = 0;
        int64_t lmax = 0;
        for(int i = N-1; i >= 0; --i)
        {
            vsum += ss[i].v;
            ss[i].f_l = vsum - (C-ss[i].x);
            ss[i].f_l_max = lmax = max(ss[i].f_l, lmax);
        }
    }
    
    //cout << "x\tv\tfr\tfl\tfrm\tflm\n";
    //for(auto&& s : ss)
    //    cout << s.x << '\t' << s.v << '\t' << s.f_r << '\t' << s.f_l << '\t' << s.f_r_max << '\t' << s.f_l_max << '\n';
       
    
    int64_t lrmax = ss[N-1].f_r_max;
    for(int i = N-1; i >= 1; --i)
    {
        lrmax = max(lrmax, ss[i].f_l - (C - ss[i].x) + ss[i-1].f_r_max);
    }
    int64_t rlmax = ss[0].f_l_max;
    for(int i = 0; i < N-1; ++i)
    {
        rlmax = max(rlmax, ss[i].f_r - ss[i].x + ss[i+1].f_l_max);
    }
    
    cout << max(0L,max(rlmax,lrmax)) << '\t';

    return 0;
}
