#include <algorithm>　　　 //STL 通用算法
#include <bitset>　　　　　//STL 位集容器
#include <cctype> //字符处理
#include <cerrno> 　　　　 //定义错误码
#include <cfloat>　　　　 //浮点数处理
#include <ciso646> //对应各种运算符的宏
#include <climits> 　　　　//定义各种数据类型最值的常量
#include <clocale> 　　　　//定义本地化函数
#include <cmath> 　　　　　//定义数学函数
#include <complex>　　　　 //复数类
#include <csignal> //信号机制支持
#include <csetjmp> //异常处理支持
#include <cstdarg> //不定参数列表支持
#include <cstddef> //常用常量
#include <cstdio> 　　　　 //定义输入／输出函数
#include <cstdlib> 　　　　//定义杂项函数及内存分配函数
#include <cstring> 　　　　//字符串处理
#include <ctime> 　　　　　//定义关于时间的函数
#include <cwchar> 　　　　 //宽字符处理及输入／输出
#include <cwctype> 　　　　//宽字符分类
#include <deque>　　　　　 //STL 双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream> 　　　 //文件输入／输出
#include <functional>　　　//STL 定义运算函数（代替运算符）
#include <limits> 　　　　 //定义各种数据类型最值常量
#include <list>　　　　　　//STL 线性列表容器
#include <locale> //本地化特定信息
#include <map>　　　　　　 //STL 映射容器
#include <memory> //STL通过分配器进行的内存分配
#include<new> //动态内存分配
#include <numeric> //STL常用的数字操作
#include <iomanip> 　　　 //参数化输入／输出
#include <ios>　　　　　　 //基本输入／输出支持
#include <iosfwd>　　　　　//输入／输出系统使用的前置声明
#include <iostream> 　　　//数据流输入／输出
#include <istream>　　　　 //基本输入流
#include <iterator> //STL迭代器
#include <ostream>　　　　 //基本输出流
#include <queue>　　　　　 //STL 队列容器
#include <set>　　　　　　 //STL 集合容器
#include <sstream>　　　　 //基于字符串的流
#include <stack>　　　　　 //STL 堆栈容器
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　 //底层输入／输出支持
#include <string>　　　　　//字符串类
#include <typeinfo> //运行期间类型信息
#include <utility>　　　　 //STL 通用模板类
#include <valarray> //对包含值的数组的操作
#include <vector>　　　　　//STL 动态数组容器
using namespace std;
 
const int maxn = 1e3 + 20;
int vis[maxn],n;
double x[maxn],y[maxn],r[maxn],dist[maxn],mp[maxn][maxn];
 
void SPFA(int s)
{
    queue<int>q;
    for(int i = 1;i <= n;i++) dist[i] = 1e10;
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    dist[s] = 0;
    vis[s] = 1;
    q.push(s);
 
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        vis[v] = 0;
        for(int i = 1;i <= n;i++)
        {
            if(dist[i] > dist[v] + mp[v][i])
            {
                dist[i] = dist[v] + mp[v][i];
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}
 
int main()
{
    while(scanf("%lf%lf%lf%lf",&x[1],&y[1],&x[2],&y[2]) != EOF)
    {
        scanf("%d",&n);
        n += 2;
        r[1] = r[2] = 0;
        mp[1][2] = mp[2][1] = sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]));
        for(int i = 3;i <= n;i++)
        {
            scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                mp[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                mp[i][j] -= r[i] + r[j];
                if(mp[i][j] < 0)
                {
                    mp[i][j] = 0;
                }
            }
        }
        SPFA(1);
        printf("%.10f\n",dist[2]);
    }
    return 0;
}
