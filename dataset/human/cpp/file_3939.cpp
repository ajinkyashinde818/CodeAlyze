#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;

constexpr double INF       = 1e+20;
constexpr int MODULO    = 1000000007;

#define int long

#define REP(i,f,n) for(int i=(f); i < (n); ++i)
#define PER(i,f,n) for(int i=(n-1); i >= f; --i)

constexpr int evx[4] = { 1, 0, -1, 0 };
constexpr int evy[4] = { 0, 1, 0, -1 };

//----------------------------------
//----------------------------------
//

inline double distance(pair<double,double> a, double r, pair<double,double> b, double br)
{
        double tmp = sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second)) - r - br;
        return tmp <= 0 ? 0 : tmp;
}


signed main()
{
    ios::sync_with_stdio(false);
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        int n;
        cin >> n;
        vector<double> x, y, r;
        for(int i = 0; i < n; ++i)
        {
                double a, b, c;
                cin >> a >> b >> c;
                x.push_back(a);
                y.push_back(b);
                r.push_back(c);
        }

        vector<vector<double>> dis;
        for(int i = 0; i < n; ++i)
        {
                dis.push_back(vector<double>());
                for(int j = 0; j < n; ++j)
                {
                        dis[i].push_back(distance({x[i],y[i]}, r[i], {x[j], y[j]}, r[j]) );
                }
        }

        for(int k = 0; k < n; ++k)
                for(int i = 0; i < n; ++i)
                        for(int j = 0; j < n; ++j)
                                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

        /* for(int i = 0; i < n; ++i) */
        /*      for(int j = 0; j < n; ++j) */
        /*              cerr << i << ',' << j << ":" << dis[i][j] << '\n'; */

        for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                {
                        /* cerr  << i << ',' << j << ":: " << distance({x[i], y[i]}, r[i], {tx, ty}, 0) */
                        /*                      + distance({x[j], y[j]}, r[j], {sx, sy}, 0) << '\n'; */

                        dis[i][j] += distance({x[i], y[i]}, r[i], {tx, ty}, 0)
                                                + distance({x[j], y[j]}, r[j], {sx, sy}, 0);
                }
        double min_dis = distance({sx,sy}, 0, {tx,ty}, 0);

        for(int i = 0; i < n; ++i)
                min_dis = min(min_dis , *min_element(dis[i].begin(), dis[i].end()));
        cout <<scientific << setprecision(10) <<  min_dis << '\n';

}
