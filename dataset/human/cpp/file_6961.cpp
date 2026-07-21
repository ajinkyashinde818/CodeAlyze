#include <cstdio>
#include <map>

std::map<int, int> map;
std::multimap<int, int> emp;
int a[200005], b[200005];
int target[200005], tcnt = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		emp.insert(std::make_pair(a[i], i));
	}
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
	{
		int cnt = 1, tcnt = 0, cur = b[i];
		while (i < n && b[i+1] == b[i]) cnt++, i++;
		// printf("%d %d %d\n", cur, cnt, emp.size());
		for (auto j = emp.begin(); tcnt < cnt && j != emp.end() && j->first < cur; j = emp.begin())
		{
			target[tcnt++] = j -> second;
			emp.erase(j);
		}
		for (auto j = emp.upper_bound(cur); tcnt < cnt && j != emp.end(); j = emp.upper_bound(cur))
		{
			if (j->first <= cur) j++;
			if (j == emp.end()) break;
			target[tcnt++] = j->second;
			emp.erase(j);
		}
		for (auto j = map.begin(); tcnt < cnt && j != map.end(); j++) target[tcnt++] = j->first;
		if (tcnt < cnt)
		{
			printf("No\n");
			return 0;
		}
		for (int j = 0; j < tcnt; j++)
		{
			if (map.count(target[j]) == 0) map[target[j]] = cur;
			else
			{
				auto l = map.find(target[j]);
				auto r = emp.find(cur);
				map[r->second] = l->second;
				map[l->first] = cur;
				emp.erase(r);
			}
		}
	}

	printf("Yes\n");
	for (int i = 1; i <= n; i++) printf("%d ", map[i]); printf("\n");
}
