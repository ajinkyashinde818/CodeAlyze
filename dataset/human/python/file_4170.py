from copy import deepcopy
m = 43
table = [[] for i in range(43)]
table[0].append(set([0]))
table[1].append(set([1]))
for i in range(2,m):
    table[i].append(set([i]))
    for j in range(1, i):
        k = i-j
        for t in table[j]:
            if k in t:
                continue
            tmp = deepcopy(t)
            tmp.add(k)
            table[i].append(tmp)
    l = max(len(a) for a in table[i])
    tmp = []
    for a in table[i]:
        if len(a) == l:
            tmp.append(a)
    table[i] = tmp
table = [max(len(j) for j in i) for i in table]

n = int(input())
def factorization(n):
    ret = {}
    for i in range(2, int(n**0.5)+1):
        while n % i == 0:
            ret[i] = ret.get(i, 0) + 1
            n //= i
    if n != 1:
        ret[n] = ret.get(n, 0) + 1
    return ret

d = factorization(n)
ans = 0
for k,v in d.items():
    ans += table[v]
print(ans)
