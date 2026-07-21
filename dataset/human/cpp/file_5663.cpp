#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cassert>
#include <queue>

struct btree_node
{
    btree_node(void):zero(nullptr), one(nullptr){}
    btree_node *zero;
    btree_node *one;
};

int main(void)
{
    int N;
    long long L;
    std::cin >> N >> L;
    // Make a tree
    btree_node bn[100005];
    btree_node *next_node = bn+1;
    for(int i=0; i<N; ++i)
    {
        std::string line;
        std::cin >> line;
        auto p = &bn[0];
        for(auto c : line)
        {
            if(c == '0')
            {
                if(!p->zero)
                {
                    p->zero = next_node;
                    p = next_node;
                    ++next_node;
                }
                else
                    p = p->zero;
            }
            else // 1
            {
                if(!p->one)
                {
                    p->one = next_node;
                    p = next_node;
                    ++next_node;
                }
                else
                    p = p->one;
            }
        }
        assert(p-&bn[0] < 100005);
    }
    long long flag = 0;
    std::queue<std::pair<btree_node*,int>> Q;
    Q.push(std::make_pair(&bn[0], 0));
    while(!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        if(p.first->zero)
        {
            Q.push(std::make_pair(p.first->zero, p.second+1));
        }
        else
        {
            long long a = L-p.second;
            flag ^= a&-a;
        }
        if(p.first->one)
        {
            Q.push(std::make_pair(p.first->one, p.second+1));
        }
        else
        {
            long long a = L-p.second;
            flag ^= a&-a;
        }
    }
    std::cout << (flag ? "Alice" : "Bob") << std::endl;
    return 0;
}
