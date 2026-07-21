from itertools import combinations

n = int(input())
m = 1
while m * (m+1) // 2 <= n:
    m += 1
m -= 1
if m * (m+1) // 2 == n:
    print("Yes")
    k = n*2 // m
    print(k)
    ans = [[] for i in range(k)]
    c = tuple(i for i in range(k))
    for i, comb in enumerate(combinations(c, 2)):
        ans[comb[0]].append(i+1)
        ans[comb[1]].append(i+1)
    for i in ans:
        print(m, *i)

else:
    print("No")
