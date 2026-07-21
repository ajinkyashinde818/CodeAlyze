/*
对初始的A序列添加一个A[N + 1] = A[1] xor A[2] xor ... xor A[N]，容易发现题目给定的操作就是在swap(A[i], A[N + 1])，同时A[N + 1] = A[1] xor A[2] xor ... xor A[N]的性质一直满足。无解可以判断
可以发现，N + 1这个位置的用处是一个“中间站”
把所有A[i] != B[i]的位置提出来，对于剩下的位置，考虑某一种方案中，如果要把A[i]的值赋给A[j]，就i -> j连一条边，最优方案中显然每个点入度 = 出度 = 1，可以看成置换P，形成了若干个环
考虑两个不同的环中有两个点a和b满足A[a] = A[b]，那么可以swap(P[a], P[b])，来做到合并2个环同时保持合法。这样可以使得每个权值相同的点都在同一个环上。下面考虑每个环，设环大小为n 
(1)对于含有N + 1的环，可以考虑从该点出发在环上走，走到x时swap(A[P[x]], A[N + 1])，不走到N + 1的后继（swap(A[N + 1], A[N + 1])无意义），就可以用n - 1次操作完成该环的赋值了
(2)若不存在环(1)，但是存在权值 = A[N + 1]的点的环，可以考虑从该点出发在环上走，走到x时swap(A[P[x]], A[N + 1])，走到N + 1的后继，就可以用n次操作完成该环的赋值了 
(3)对于剩下的环，从任意一个点s出发，先swap(A[s], A[N + 1])，然后从该点开始在环上走，走到x时swap(A[P[x]], A[N + 1])，就可以用n + 1次操作完成该环的赋值了
故Ans = Sum{[A[x] != B[x]]   |   1 <= x <= N} + (3)环的数量 - [N + 1在一个环中]，考虑如何最小化(3)环的数量
*/
/*
把权值作为点建图，当A[x] != B[x]时就B[x] -> A[x]连一条边。对于每个点都满足入度 = 出度 = 该权值的点有多少个，所以每个底图联通块都存在欧拉回路
显然一个欧拉回路能够构造出来一个置换P的环，所以连完边直接算答案 
*/

#include <map>
#include <cstdio>

using namespace std;
const int Max_N(100050);

int N, A[Max_N], B[Max_N], Ans;
bool Flag1, Flag2;
map<int, int> In, Ot, Father;

int Get_Father(int x)
{
	return Father[x] == x ? x : Father[x] = Get_Father(Father[x]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1;i <= N;++i)
		scanf("%d", A + i), A[N + 1] ^= A[i];
	for (int i = 1;i <= N;++i)
		scanf("%d", B + i), B[N + 1] ^= B[i];
	for (int i = 1;i <= N + 1;++i)
		if (A[i] != B[i])
		{
			++Ans;
			if (!Father.count(A[i]))
				Father[A[i]] = A[i];
			if (!Father.count(B[i]))
				Father[B[i]] = B[i];
			Father[Get_Father(A[i])] = Get_Father(B[i]);
			++In[A[i]], ++Ot[B[i]];
			Flag1 |= ((A[i] == A[N + 1]) || (B[i] == B[N + 1]));
			Flag2 |= (i == N + 1);
		}
	for (map<int, int>::iterator it = In.begin();it != In.end();++it)
		if (Ot[it -> first] != it -> second)
		{
			printf("-1");
			return 0;
		}
	for (map<int, int>::iterator it = Father.begin();it != Father.end();++it)
		if (Get_Father(it -> first) == it -> first)
			++Ans;
	if (Flag2)
		Ans -= 2;
	else
		if (Flag1)
			Ans -= 1;
	printf("%d", Ans);
	return 0;
}
