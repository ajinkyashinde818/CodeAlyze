#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <functional>
#include <iostream>
#include <numeric>
#define SIZE 10005
 
using namespace std;
typedef long long int ll;
// typedef pair <int,int> P;
 
int pair[SIZE];
 
int main()
{
	int n;
    long long int sum = 0;
    int count = 0;
    std::cin >> count;
    long long int value[count];
    int zero_count = 0;
    for (int i = 0; i < count; i++)
    {
        std::cin >> value[i];
        if (value[i] <= 0){
            zero_count += 1;
            value[i] *= -1;
        }
    }
    std::sort(value, value+count);
    for (int i = 1; i < count; i++)
    {
        sum = sum + value[i];
    }
    if (zero_count % 2 == 1)
    {
        sum -= value[0];
    }else {
        sum += value[0];
    }
	std::cout << sum << std::endl;

    return 0;
    
}
